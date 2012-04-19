#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

const int INF = 987654321;
map< char, int > V;

int roman( char* s ) {
    int value = 0, prevval = INF, l = strlen( s );

    for ( int i = 0; i < l; ++i ) {
        if ( V[ s[ i ] ] > prevval ) {
            value -= 2 * V[ s[ i - 1 ] ];
        }
        value += V[ s[ i ] ];
        prevval = V[ s[ i ] ];
    }
    return value;
}

void numeral( char* s, int value ) {
    map< int, string > VP;

    for ( map< char, int >::iterator i = V.begin(); i != V.end(); ++i ) {
        VP[ i->second ] = string( 1, i->first );
    }
    VP[ 900 ] = "CM";
    VP[ 400 ] = "CD";
    VP[  90 ] = "XC";
    VP[  40 ] = "XL";
    VP[   9 ] = "IX";
    VP[   4 ] = "IV";

    for ( map< int, string >::reverse_iterator i = VP.rbegin(); i != VP.rend(); ++i ) {
        if ( value >= i->first ) {
            for ( int j = 0; j < i->second.length(); ++j ) {
                s[ j ] = i->second[ j ];
            }
            return numeral( s + i->second.length(), value - i->first );
        }
    }
    s[ 0 ] = '\0';
}

int main() {
    FILE *in = fopen( "roman.txt", "r" );
    char s[ 50 ], p[ 50 ];
    int c = 0, value = 0;

    V[ 'I' ] = 1;
    V[ 'V' ] = 5;
    V[ 'X' ] = 10;
    V[ 'L' ] = 50;
    V[ 'C' ] = 100;
    V[ 'D' ] = 500;
    V[ 'M' ] = 1000;

    while ( !feof( in ) ) {
        fscanf( in, "%s", s );
        numeral( p, roman( s ) );
        c += strlen( s ) - strlen( p );
    }
    printf( "Solution = %i\n", c );
    return 0;
}
