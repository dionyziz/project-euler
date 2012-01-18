#include <cstdio>
#include <cmath>

using namespace std;

#define MIN( a, b ) ( ( a ) < ( b )? ( a ): ( b ) )
#define MAX( a, b ) ( ( a ) > ( b )? ( a ): ( b ) )

typedef unsigned long long int number;

int N = 15;

struct fraction {
    number numerator;
    number denominator;
};

number gcd( number a, number b ) {
    number M = MAX( a, b );
    number m = MIN( a, b );

    if ( m == 0 ) {
        return M;
    }
    return gcd( m, M % m );
}

fraction make_fraction( number numerator, number denominator ) {
    fraction ret;
    number g = gcd( numerator, denominator );

    ret.numerator = numerator / g;
    ret.denominator = denominator / g;

    return ret;
}

fraction operator +( fraction a, fraction b ) {
    return make_fraction( a.numerator * b.denominator + b.numerator * a.denominator, a.denominator * b.denominator );
}

fraction operator *( fraction a, fraction b ) {
    return make_fraction( a.numerator * b.numerator, a.denominator * b.denominator );
}

fraction make_fraction( number value ) {
    return make_fraction( value, 1 );
}

fraction prob( number i ) {
    return make_fraction( 1, 1 + i );
}

fraction invprob( number i ) {
    return make_fraction( i, 1 + i );
}

int main() {
    number n, i, j, c;
    fraction total = make_fraction( 0 );
    number a = 9, b = 21;

    for ( i = 2047; i < pow( 2, N ); ++i ) {
        n = i;
        j = N;
        c = 0;
        fraction p = make_fraction( 1 );

        // printf( "Examining binary number: " );
        while ( n ) {
            // printf( "%i", n % 2 );
            if ( n % 2 == 1 ) {
                // printf( "Win mul: %llu / %llu\n", prob( j ).numerator, prob( j ).denominator );
                p = p * prob( j );
                ++c;
            }
            else {
                // printf( "Los mul: %i / %i\n", invprob( j ).numerator, invprob( j ).denominator );
                p = p * invprob( j );
            }
            n /= 2;
            --j;
        }
        // printf( " " );
        if ( c > 7 ) {
            // printf( "PASS with probability %llu / %llu\n", p.numerator, p.denominator );
            total = total + p;
            printf( "Total probability = %llu / %llu\n", total.numerator, total.denominator );
        }
        else {
            // printf( "FAIL\n" );
        }
        // return 0;
    }

    printf( "Total probability = %llu / %llu\n", total.numerator, total.denominator );

    return 0;
}
