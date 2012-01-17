#include <stdio.h>
#include <string.h>

const unsigned long long int MAX_N = 1000000000;

inline int reverse( char* s, char* t ) {
    int len = strlen( s );
    int i;

    for ( i = 0; i < len; ++i ) {
        t[ i ] = s[ len - i - 1 ];
    }
}

inline int veryodd( int a ) {
    char ori[ 20 ];
    int i = 0;

    sprintf( ori, "%i", a );
    while ( *( ori + i ) ) {
        switch ( *( ori + i ) ) {
            case '1': case '3': case '5':
            case '7': case '9':
                break;
            default:
                return 0;
        }
        ++i;
    }
    return 1;
}

inline int reversible( unsigned long long int a ) {
    char ori[ 20 ];
    char rev[ 20 ];
    int b;

    sprintf( ori, "%i", a );
    reverse( ori, rev );
    b = atoi( rev );
    return veryodd( a + b );
}

int main() {
    unsigned long long i;
    unsigned long long int cnt = 0;
    char a[ 20 ];
    char b[ 20 ];

    for ( i = 12; i < MAX_N; ++i ) {
        if ( i % 10 == 0 ) {
            continue;
        }
        if ( reversible( i ) ) {
            ++cnt;
        }
        if ( i % 100000 == 1 ) {
            printf( "\rSearching %2.0f%%", 100 * ( float )i / MAX_N );
        }
    }

    printf( "There are %i reversible numbers below %i.\n", cnt, MAX_N );

    return 0;
}
