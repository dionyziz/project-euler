#include <stdio.h>
#include <math.h>

const float EPSILON = 0.1;
const long long int MAX_SIDE = 333333333;
const long long int MIN_SIDE = 2;

inline int AlmostEqualUlps(float A, float B) {
    if (A == B)
        return 1;
    int intDiff = abs(*(int*)&A - *(int*)&B);
    if (intDiff <= 10)
        return 1;
    return 0;
}

int main() {
    long long int a;
    long long int b;
    float e;
    float s;
    long long int sum = 0;
    
    for ( a = MIN_SIDE; a <= MAX_SIDE; ++a ) {
        for ( b = a - 1; b <= a + 1; b += 2 ) {
            s = ( float )( a + a + b ) / 2.0;
            e = sqrt( s * ( s - a ) * ( s - b ) * ( s - a ) );
            if ( AlmostEqualUlps( e, ( float )( int )e ) ) {
                sum += a + a + b;
                // printf( "Found! %i-%i-%i\n", a, a, b );
            }
        }
        if ( a % 10000 == 0 ) {
            printf( "\rSearching... %0.2f%%", 100 * ( float )a / MAX_SIDE );
        }
    }
    
    printf( "\n%lli\n", sum );

    return 0;
}
