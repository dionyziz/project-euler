#include <cstdio>
#include <cmath>
#include <cassert>

using namespace std;

typedef unsigned long long int LL;

const int UPPER_BOUND = 2 * 3 * 5 * 5 * 7 * 11 * 13 * 17 * 19 * 23;
const int PRIME_COUNT = 9;
int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };

struct fraction {
    LL numerator;
    LL denominator;
};

struct factoredInteger {
    int value;
    int primeExponents[ PRIME_COUNT ];
    int phi;
    bool valid;
};

int maxExponents[ PRIME_COUNT ];
int progress = 0;

inline LL gcd( LL a, LL b ) {
    if ( a < b ) {
        return gcd( b, a );
    }
    if ( b == 0 ) {
        return a;
    }
    return gcd( b, a % b );
}

inline fraction makeFraction( LL numerator, LL denominator ) {
    LL factor = gcd( numerator, denominator );
    fraction ret;

    ret.numerator = numerator / factor;
    ret.denominator = denominator / factor;

    return ret;
}

inline fraction operator *( fraction a, fraction b ) {
    return makeFraction(
        a.numerator * b.numerator,
        a.denominator * b.denominator
    );
}

bool operator <( fraction a, fraction b ) {
    return ( LL )a.numerator * b.denominator < ( LL )b.numerator * a.denominator;
}

inline void calcPhi( factoredInteger* n ) {
    int i;
    fraction phi = makeFraction( n->value, 1 );

    // printf( "Finding phi of %i\n", n->value );

    for ( i = 0; i < PRIME_COUNT; ++i ) {
        if ( n->primeExponents[ i ] ) {
            // printf( "mul\n" );
            phi = phi * makeFraction( primes[ i ] - 1, primes[ i ] );
        }
    }
    // printf( "numerator = %llu\n", phi.numerator );
    // printf( "denominator = %llu\n", phi.denominator );
    assert( phi.denominator == 1 );

    n->phi = phi.numerator;
}

inline void calcValue( factoredInteger* n ) {
    int i;

    // printf( "Calculating value: " );
    n->value = 1;
    n->valid = true;
    for ( i = 0; i < PRIME_COUNT; ++i ) {
        n->value *= pow( primes[ i ], n->primeExponents[ i ] );
        if ( n->value < 0 ) {
            // printf( "overflow\n" );
            // overflow
            n->valid = false;
            return;
        }
        // printf( "%i ", n->value );
    }
    // printf( "\n" );
}

inline void zero( factoredInteger* n ) {
    int i;

    for ( i = 0; i < PRIME_COUNT; ++i ) {
        n->primeExponents[ i ] = 0;
    }
    calcValue( n );
}

inline bool increment( factoredInteger* n ) {
    int digit = 0;

    ++n->primeExponents[ digit ];
    while ( n->primeExponents[ digit ] == maxExponents[ digit ] + 1
            && digit < PRIME_COUNT ) {
        n->primeExponents[ digit ] = 0;
        ++digit;
        ++n->primeExponents[ digit ];
        if ( digit == PRIME_COUNT - 3 ) {
            printf( "%i%%...\n", 100 * progress / 294 );
            ++progress;
        }
    }
    calcValue( n );
    if ( digit == PRIME_COUNT ) {
        // no more to increment
        return false;
    }
    // can keep incrementing
    return true;
}

inline void print( factoredInteger n ) {
    int i;

    printf( "%i = ", n.value );
    for ( i = 0; i < PRIME_COUNT; ++i ) {
        if ( n.primeExponents[ i ] ) {
            printf( "%i^%i ", primes[ i ], n.primeExponents[ i ] );
        }
    }
    printf( "\n" );
}

int main() {
    int i, p;
    fraction boundary = makeFraction( 15499, 94744 );
    // fraction boundary = makeFraction( 4, 10 );
    factoredInteger n;

    for ( i = 0; i < PRIME_COUNT; ++i ) {
        p = primes[ i ];
        // log_p( upper_bound ) = log_e( upper_bound ) / log_e( p )
        maxExponents[ i ] = floor( log( UPPER_BOUND ) / log( p ) );
        printf( "%i^%i >= %i\n", p, maxExponents[ i ], UPPER_BOUND );
    }

    zero( &n );
    do {
        if ( n.valid ) {
            // printf( "Calc phi:\n" );
            calcPhi( &n );
            // printf( "Comparison:\n" );
            if ( makeFraction( n.phi, n.value - 1 ) < boundary ) {
                printf( "d = %i\n", n.value );
            }
            // print( n );
            // printf( "Increment:\n" );
        }
    } while ( increment( &n ) );

    // printf( "Your numerical assumption was incorrect; there is no such number that consists of small prime factors. Sorry.\n" );

    return 0;
}
