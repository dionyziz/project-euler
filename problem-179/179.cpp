#include <cstdio>

using namespace std;

const int N = 10000000;

int* primes = new int[ N ];
int* primeFactor = new int[ N ];
int primeCnt = 0;

void sieve() {
    for ( int candidate = 2; candidate < N; ++candidate ) {
        bool prime = true;
        for ( int i = 0; i < primeCnt; ++i ) {
            int witness = primes[ i ];
            if ( candidate % witness == 0 ) {
                prime = false;
                break;
            }
            if ( witness * witness > candidate ) {
                break;
            }
        }
        if ( prime ) {
            primes[ primeCnt++ ] = candidate;
            for ( int factor = 1; factor <= N / candidate; ++factor ) {
                primeFactor[ factor * candidate ] = candidate;
            }
        }
    }
}

int main() {
    int ret = 0;
    int prevCount = -1;

    sieve();

    for ( int i = 2; i < N; ++i ) {
        int exponent = 0;
        int j = i;
        int prevFactor = 0;
        int count = 1;

        while ( j > 1 ) {
            if ( primeFactor[ j ] != prevFactor ) {
                count *= exponent + 1;
                exponent = 0;
                prevFactor = primeFactor[ j ];
            }
            j /= primeFactor[ j ];
            ++exponent;
        }
        count *= exponent + 1;
        // printf( "d( %i ) = %i\n", i, count );
        if ( prevCount == count ) {
            ++ret;
        }
        prevCount = count;
    }
    printf( "Solution: %i\n", ret );

    return 0;
}
