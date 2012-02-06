#include <cstdio>
#include <cmath>
#include <set>

typedef unsigned long long int LL;

using namespace std;

inline LL sigma( LL i ) {
    LL sum = 0;
    LL base = 1;
    LL t = i;

    while ( t ) {
        sum += t % 10;
        t /= 10;
        base *= 10;
    }
    return sum;
}

void printSolutions( const set< LL > solutions ) {
    int i = 1;

    for ( set< LL >::iterator it = solutions.begin(); it != solutions.end(); ++it, ++i ) {
        printf( "a[ %i ] = %lli\n", i, *it );
    }
}

int main() {
    set< LL > solutions;

    for ( LL l = 1; ; ++l ) { // dove-tailing
        for ( LL s = 1; s < l; ++s ) {
            LL e = l - s;
            LL i = pow( s, e );

            if ( i > 10 ) {
                if ( sigma( i ) == s ) {
                    solutions.insert( i );
                    printf( "Found a new solution.\n" );
                    printSolutions( solutions );
                }
            }
        }
    }
    return 0;
}
