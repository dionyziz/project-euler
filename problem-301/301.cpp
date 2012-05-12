// Just a validation that the pen-and-paper formula works
// using brute force for small limits
//
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

// const char *byte_to_binary( int x ) {
//     static char b[ 9 ];
//     b[ 0 ] = '\0';
// 
//     int z;
//     for ( z = 256; z > 0; z >>= 1 ) {
//         strcat( b, ( ( x & z ) == z ) ? "1" : "0" );
//     }
// 
//     return b;
// }

int main() {
    int cnt = 0;

    for ( int n = 1; n <= pow( 2, 7 ); ++n ) {
        if ( ( ( n ^ ( 2 * n ) ) ^ ( 3 * n ) )== 0 ) {
            // printf( "%s ^ ", byte_to_binary( n ) );
            // printf( "%s ^ ", byte_to_binary( 2 * n ) );
            // printf( "%s = 0\n", byte_to_binary( 3 * n ) );
            ++cnt;
        }
    }
    printf( "%i\n", cnt );
    return 0;
}
