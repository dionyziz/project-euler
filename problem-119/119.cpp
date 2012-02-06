#include <cstdio>
#include <cmath>

typedef unsigned long long int LL;
typedef long double LLD;

const LLD EPSILON = 0.00001;

int main() {
    LLD l;
    LL i, t, base, sum;
    int j, prev = 0;

    for ( i = 10, j = 1; j <= 100; ++i ) {
        sum = 0;
        base = 1;
        t = i;
        while ( t ) {
            sum += t % 10;
            t /= 10;
            base *= 10;
        }
        if ( sum > 1 ) {
            l = log( ( LLD )i ) / log( ( LLD )sum );
            if ( fabs( l - ( LL )l ) < EPSILON && pow( sum, ( LL )l ) == i ) {
                // whole number
                printf( "a[ %i ] = %lli\n", j, i );
                ++j;
            }
        }
    }
    return 0;
}
