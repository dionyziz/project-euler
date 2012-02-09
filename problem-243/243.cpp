#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <set>
#include <vector>

using namespace std;

typedef unsigned long long int LL;

const LL RES_NUM = 15499;
const LL RES_DENOM = 94744;

set< int > primes;

int gcd( int a, int b ) {
    assert( a <= b );
    if ( a == 0 ) {
        return b;
    }
    return gcd( b % a, a );
}

inline int getDivisor( int candidate ) {
    // sieve of eratosthenes primality check and return divisor
    bool prime;

    if ( candidate % 2 == 0 ) {
        return 2;
    }

    prime = true;
    for ( set< int >::iterator disprover = primes.begin(); disprover != primes.end(); ++disprover ) {
        assert( *disprover < candidate );
        if ( ( *disprover ) * ( *disprover ) > candidate ) {
            break;
        }
        if ( candidate % *disprover == 0 ) {
            return *disprover;
        }
    }
    if ( prime ) {
        primes.insert( candidate );
        return candidate;
    }
}

int main() {
    vector< int > phi;
    int p, q, d;

    primes.insert( 2 );

    // evaluate Euler's phi function for all numbers of interest
    // use dynamic programming to find phi
    phi.push_back( 0 ); // phi[ 0 ] = 1
    phi.push_back( 1 ); // phi[ 1 ] = 1
    for ( int n = 2; ; ++n ) {
        if ( n % 50000 == 0 ) {
            printf( "\rSolving for denominator %i.", n );
        }
        p = getDivisor( n );
        if ( p == n ) {
            // n is a prime
            // phi[ n ] = n - 1
            phi.push_back( n - 1 );
        }
        else {
            // n is composite
            // phi( p * q ) = phi( p ) * phi( q ) * gcd( p, q ) / phi( gcd( p, q ) )
            q = n / p;
            d = gcd( p, q );
            // set phi[ n ]
            phi.push_back( ( LL )phi[ p ] * phi[ q ] * d / phi[ d ] );
        }
        // compare phi[ n ] / ( n - 1 ) < RES_NUM / RES_DENOM
        // Resilience of denominator n is phi[ n ] / ( n - 1 )
        if ( RES_DENOM * phi[ n ] < RES_NUM * ( n - 1 ) ) {
            printf( "\nSolution: %i\n", n );
            return 0;
        }
    }
}
