#include <cstdio>
#include <cmath>

using namespace std;

int N = 15;

struct fraction {
    int numerator;
    int denominator;
};

fraction operator +( fraction a, fraction b ) {
    fraction ret;

    ret.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    ret.denominator = a.denominator * b.denominator;

    return ret;
}

fraction operator *( fraction a, fraction b ) {
    fraction ret;

    ret.numerator = a.numerator * b.numerator;
    ret.denominator = a.denominator * b.denominator;
}

fraction make_fraction( int numerator, int denominator ) {
    fraction ret;

    ret.numerator = numerator;
    ret.denominator = denominator;

    return ret;
}

fraction prob( int i ) {
    return make_fraction( 1, 1 + i );
}

int main() {
    int n, i, j, c;
    fraction total = make_fraction( 0, 1 );

    for ( i = 0; i < pow( 2, N ); ++i ) {
        n = i;
        j = N;
        c = 0;
        fraction p = make_fraction( 1, 1 );

        while ( n ) {
            if ( n % 2 == 1 ) {
                p = p * prob( j );
                ++c;
            }
            n /= 2;
            --j;
        }
        if ( c > 7 ) {
            total = total + p;
        }
    }

    printf( "Total probability = %i / %i\n", total.numerator, total.denominator );

    return 0;
}
