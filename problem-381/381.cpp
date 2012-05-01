#include "euclidean.h"
#include "millerrabin.h"
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <ctime>

typedef unsigned long long int lli;

using namespace std;

inline int S( lli p ) {
    lli s, fact;

    s = fact = p - 1;
    for ( int k = p - 1; k > p - 5; --k ) {
        int inv = inverse( k, p );
        // assert( inv >= 0 );
        fact = ( fact * inv ) % p;
        s = ( s + fact ) % p;
    }
    return s;
}

int main() {
    lli solution = 0;
    int progress = 0;
    lli N = pow( 10, 8 );

    for ( int p = 5; p < N; p += 2 ) {
        if ( isPrime( p ) ) {
            solution += S( p );
        }
        if ( p % 1000000 == 1 ) {
            printf( "Progress: %i%%\n", progress );
            ++progress;
        }
    }
    printf( "%llu\n", solution );
}
