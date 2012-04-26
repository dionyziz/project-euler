#include "euclidean.h"
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
#include <utility>

using namespace std;

int main() {
    int solution = 0;
    int N = pow( 10, 8 );
    int* primes;
    int numPrimes = 2;

    primes = ( int* )malloc( 6000000 * sizeof( int ) );
    primes[ 0 ] = 2;
    primes[ 1 ] = 3;

    for ( long long int p = 5; p < N; p += 2 ) {
        bool found = true;
        for ( int prime = 0; prime < numPrimes; ++prime ) {
            if ( p % primes[ prime ] == 0 ) {
                found = false;
                break;
            }
            if ( primes[ prime ] * primes[ prime ] > p ) {
                break;
            }
        }
        if ( found ) {
            primes[ numPrimes ] = p;
            ++numPrimes;
            int s, fact;
            s = fact = p - 1;
            for ( int k = p - 1; k > p - 5; --k ) {
                int inv = inverse( k, p );
                fact = ( fact * inv ) % p;
                s = ( s + fact ) % p;
            }
            solution += s;
        }
        if ( p % 1000000 == 1 ) {
            printf( "Progress: %i%%\n", 100 * p / N );
        }
    }
    printf( "%i\n", solution );
}
