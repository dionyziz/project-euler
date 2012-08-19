/*
 * This C++ solution is incorrect.
 * It's here for reference purposes. Use Python solution instead.
 */

#include <cstdio>
#include <cassert>

using namespace std;

typedef long long int llu;

inline llu s( int p1, int p2 ) {
    int i = 0, sp1 = p1, dig = 1;

    while ( sp1 ) {
        dig *= 10;
        sp1 /= 10;
    }

    while ( true ) {
        llu candidate = i * dig + p1;

        if ( candidate % p2 == 0 ) {
            return candidate;
        }
        ++i;
    }
}

int main() {
    const int N = 1000000;
    llu sigma = 0;
    int primes[ N ];
    int primecnt = 3;

    primes[ 0 ] = 2;
    primes[ 1 ] = 3;
    primes[ 2 ] = 5;

    int prev = 5, candidate = 7;

    while ( true ) {
        bool prime = true;
        for ( int witness = 0; witness < primecnt; ++witness ) {
            if ( candidate % primes[ witness ] == 0 ) {
                prime = false;
            }
        }
        if ( prime ) {
            primes[ primecnt++ ] = candidate;
            int result = s( prev, candidate );
            assert( result > 0 );
            sigma += result;
            // printf( "s( %i, %i ) = %llu\n", prev, candidate, sigma );
            prev = candidate;
            if ( prev > N ) {
                break;
            }
        }
        candidate += 2;
        if ( candidate % 1000 == 1 ) {
            printf( "%i%%\n", ( 100 * candidate ) / N );
        }
    }

    printf( "%llu\n", sigma );

    return 0;
}
