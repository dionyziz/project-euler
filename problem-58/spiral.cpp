#include <cstdio>
#include <set>
#include <cmath>

using namespace std;

set< long long > primes;

long long bigprime;

bool is_prime( long long p ) {
    static long long maxp = 3;
    double sqr = sqrt( maxp );
    bool isprime;
    set< long long >::iterator i;
    long long prime;

    while ( maxp < p ) {
        maxp += 2;
        isprime = true;
        sqr += 2;
        for ( i = primes.begin(); i != primes.end(); ++i ) {
            prime = *i;
            if ( prime > sqr ) {
                break;
            }
            if ( maxp % prime == 0 ) {
                prime = false;
                break;
            }
        }
        if ( prime ) {
            bigprime = maxp;
            // printf( "Found a prime: %i\n", bigprime );
            primes.insert( maxp );
        }
    }

    i = primes.find( p );
    return i != primes.end();
}

int main() {
    primes.insert( 2 );
    primes.insert( 3 );

    long long current = 9;
    int side = 2;
    int primescount = 3;
    int total = 5;
    do {
        side += 2;
        for ( int q = 0; q < 4; ++q ) {
            current += side;
            if ( is_prime( current ) ) {
                ++primescount;
            }
            ++total;
        }
        if ( side % 10 == 0 ) {
            printf( "\rCalculating... Ratio at %f%%. Last known prime: %i", 100 * ( ( float )primescount / total ), bigprime );
        }
        if ( total > 10 * primescount ) {
            printf( "\nSide %i has %i primes and %i in total.\n", side + 1, primescount, total );
            printf( "Its ratio is %f%%\n", 100 * ( ( float )primescount / total ) );
            return 0;
        }
    } while ( true );

    return 1;
}
