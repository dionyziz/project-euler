#include <cstdio>

using namespace std;

int memoization[ 10000 ];

int fib( int n ) {
    if ( n == 0 || n == 1 ) {
        return 1;
    }
    if ( memoization[ n ] == 0 ) {
        memoization[ n ] = fib( n - 1 ) + fib( n - 2 );
    }
    return memoization[ n ];
}

int main() {
    int f = fib( 0 );
    int i = 0, sum = 0;

    while ( f <= 4000000 ) {
        f = fib( i );
        if ( f % 2 == 0 ) {
            sum += f;
        }
        ++i;
    }
    printf( "%i\n", sum );

    return 0;
}
