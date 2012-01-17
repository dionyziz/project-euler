#include <cstdio>
#include <cstring>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

const int N = 80;

int A[ N + 1 ][ N + 1 ], J[ N + 1 ][ N + 1 ];

int main() {
    FILE* fi = fopen( "matrix.txt", "r" );
    int i, j, k, l, s, m = 987654321;

    for ( i = 1; i <= N; ++i ) {
        for ( j = 1; j <= N; ++j ) {
            fscanf( fi, "%i", &A[ j ][ i ] );
            if ( j != N ) {
                fscanf( fi, "," );
            }
        }
    }
    fclose( fi );
    memset( J, 64, ( N + 1 ) * ( N + 1 ) * sizeof( int ) );
    memset( J,  0, ( N + 1 ) * sizeof( int ) );
    for ( j = 1; j <= N; ++j ) {
        for ( i = 1; i <= N; ++i ) {
            for ( k = 1; k <= N; ++k ) {
                for ( s = 0, l = MIN( k, i ); l <= MAX( k, i ); ++l ) {
                    s += A[ j ][ l ];
                }
                J[ j ][ i ] = MIN( J[ j ][ i ], J[ j - 1 ][ k ] + s );
                m = MIN( m, J[ N ][ i ] );
            }
        }
    }
    printf( "%i\n", m );

    return 0;
}
