#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "eta.h"

using namespace std;

const int N = 64000000;

int* sigma;

int main() {
    ETA e;

    sigma = ( int* )malloc( N * sizeof( int ) );

    printf( "Populating sigmas...\n" );
    for ( int i = 1; i < N; ++i ) {
        for ( int j = i; j < N; j += i ) {
            sigma[ j ] += i * i;
        }
        if ( i % 10000 == 0 ) {
            printf( "\rETA: " );
            e.print( ( float )i / N );
        }
    }

    int c = 0;

    for ( int n = 1; n < N; ++n ) {
        int s = floor( sqrt( sigma[ n ] ) );

        if ( s * s == sigma[ n ] ) {
            c += n;
        }
    }

    printf( "\n%i\n", c );

    return 0;
}
