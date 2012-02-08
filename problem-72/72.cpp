#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <set>

using namespace std;

typedef unsigned long long int LL;

const int N = 1000000;

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
    for ( int candidate = 3; candidate <= N; ++candidate ) {
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
    for ( int n = 2; n <= N; ++n ) {
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
}

int main() {
    LL sum = 0;

    phi = ( int* )malloc( ( N + 1 ) * sizeof ( int ) );
    divisor = ( int* )malloc( ( N + 1 ) * sizeof ( int ) );

    eratosthenes();
    calcPhi();

    for ( int i = 1; i <= N; ++i ) {
        // calculate phi series
        sum += ( LL )phi[ i ];
    }

    printf( "Solution: %llu\n", ( sum + 1 ) - 2 );

    return 0;
}
