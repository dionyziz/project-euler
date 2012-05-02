#include <cstdio>
#include <map>
#include <cmath>

using namespace std;

const int N = 100000000;

int main() {
    int* primes;
    int primeCnt = 2;
    map< int, int > pi;

    primes = new int[ 6000000 ]; // pi( N )

    primes[ 0 ] = 2;
    primes[ 1 ] = 3;
    pi[ 2 ] = 1;
    pi[ 3 ] = 2;

    for ( int candidate = 5; candidate < N; ++candidate ) {
        bool prime = true;
        for ( int witness = 0; witness < primeCnt; ++witness ) {
            if ( candidate % primes[ witness ] == 0 ) {
                prime = false;
                break;
            }
            if ( witness * witness > candidate ) {
                break;
            }
        }
        if ( prime ) {
            // printf( "%i\n", candidate );
            primes[ primeCnt++ ] = candidate;
            pi[ candidate ] = primeCnt;
            // printf( "pi( %i ) = %i\n", candidate, pi[ candidate ] );
        }
        if ( candidate % 1000000 == 1 ) {
            printf( "%i%%\n", 100 * candidate / N );
        }
    }

    int ret = 0;
    for ( int factor = 0; factor < primeCnt; ++factor ) {
        // printf( "First factor: %i\n", primes[ factor ] );
        int maxfactor = min( N / primes[ factor ], primes[ factor ] );
        map< int, int >::iterator it = pi.upper_bound( maxfactor );
        if ( it == pi.end() ) {
            // printf( "No primes under %i\n", maxfactor );
            continue;
        }
        --it; 
        if ( it == pi.end() ) {
            // printf( "No primes under %i\n", maxfactor );
            continue;
        }
        // printf( "pi( %i ) = %i\n", maxfactor, it->second );
        ret += it->second;
    }
    printf( "Solution: %i\n", ret );

    return 0;
}
