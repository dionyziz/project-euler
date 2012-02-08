#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <set>

using namespace std;

typedef unsigned long long int LL;

const int N = 40000000;
const int LENGTH = 25;

set< int > primes;
int* divisor;
int* phi;

int gcd( int a, int b ) {
    assert( a <= b );
    if ( a == 0 ) {
        return b;
    }
    return gcd( b % a, a );
}

void eratosthenes() {
    bool prime;

    primes.insert( 2 );
    for ( int candidate = 3; candidate < N; ++candidate ) {
        if ( candidate % 10000 == 1 ) {
            printf( "\rFinding primes... %i%%", ( ( LL )100 * candidate / N ) );
        }
        prime = true;
        for ( set< int >::iterator disprover = primes.begin(); disprover != primes.end(); ++disprover ) {
            assert( *disprover < candidate );
            if ( ( *disprover ) * ( *disprover ) > N ) {
                break;
            }
            if ( candidate % *disprover == 0 ) {
                divisor[ candidate ] = *disprover;
                prime = false;
                break;
            }
        }
        if ( prime ) {
            primes.insert( candidate );
            divisor[ candidate ] = candidate;
        }
    }
    printf( "\rFinding primes... 100%%\n" );
}

void calcPhi() {
    // evaluate phi for all numbers of interest
    // use dynamic programming to find phi
    phi[ 1 ] = 1;
    for ( int n = 2; n < N; ++n ) {
        if ( n % 50000 == 0 ) {
            printf( "\rCalculating phi... %i%%", ( ( LL )100 * n / N ) );
        }
        if ( primes.find( n ) != primes.end() ) {
            // n is a prime
            phi[ n ] = n - 1;
        }
        else {
            // n is composite
            // phi( p * q ) = phi( p ) * phi( q ) * gcd( p, q ) / phi( gcd( p, q ) )
            int p = divisor[ n ];
            int q = n / p;
            int d = gcd( p, q );
            phi[ n ] = ( LL )phi[ p ] * phi[ q ] * d / phi[ d ];
        }
    }
    printf( "\rCalculating phi... 100%%\n" );
    printf( "phi[ %i ] = %i\n", N - 1, phi[ N - 1 ] );
}

int main() {
    LL sum = 0;
    int* chain;

    chain = ( int* )malloc( N * sizeof( int ) );
    divisor = ( int* )malloc( N * sizeof( int ) );
    phi = ( int* )malloc( N * sizeof( int ) );

    eratosthenes();
    calcPhi();

    // use dynamic programming to evaluate the chains
    chain[ 1 ] = 1;
    for ( int i = 2; i < N; ++i ) {
        chain[ i ] = chain[ phi[ i ] ] + 1;
        // printf( "chain[ %i ] = %i\n", i, chain[ i ] );
        if ( primes.find( i ) != primes.end() && chain[ i ] == LENGTH ) {
            sum += i;
        }
    }
    printf( "Solution: %llu\n", sum );

    return 0;
}
