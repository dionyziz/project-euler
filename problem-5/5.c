#include <stdio.h>

int main() {
    const int base = 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19;
    int result = 0;
    int i = 1;
    int j;
    int divisible;

    while ( 1 ) {
        ++result;
        // result = i * base;
        divisible = 1;
        for ( j = 1; j < 20; ++j ) {
            if ( result % j != 0 ) {
                divisible = 0;
                break;
            }
        }
        if ( divisible ) {
            printf( "Solution: %i\n", result );
            return 0;
        }
        ++i;
    }

    return 0;
}

