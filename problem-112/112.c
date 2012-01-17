#include <stdio.h>

inline int sign( int a ) {
    return a == 0? 0: (a > 0? 1: -1);
}

inline char isbouncy( long long int a ) {
    char buffer[ 20 ];
    int diff = 0;
    int newdiff;
    char i = 0;

    sprintf( buffer, "%i-", a );
    while ( buffer[ i + 1 ] != '-' ) {
        newdiff = sign( buffer[ i ] - buffer[ i + 1 ] );
        if ( newdiff != 0 ) {
            if ( diff != 0 ) {
                if ( newdiff != diff ) {
                    return 1;
                }
            }
            diff = newdiff;
        }
        ++i;
    }
    return 0;
}

int main() {
    long long int bouncy = 0;
    long long int total = 0;
    long long int i = 1;

    while ( 1 ) {
        if ( isbouncy( i ) ) {
            ++bouncy;
        }
        ++total;

        if ( 100 * bouncy >= 99 * total ) {
            printf( "\n\nSolution: Number %i is the first to have %2.0f%% bounciness with %i bouncy / %i total.\n", i, 100 * ( float )bouncy / total, bouncy, total );
            return;
        }

        if ( total % 1000 == 0 ) {
            printf( "\r%2.0f%%", 100 * ( float )bouncy / total );
        }
        ++i;
    }
    return 0;
}

