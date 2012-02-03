#include <cstdio>
#include <cstdlib>

using namespace std;

int C = 3, N = 1;
int powersets = 1 << ( 2 * C );
int* prevbuckets;
int* buckets;

void printBuckets() {
    int i;
    for ( i = 0; i < powersets; ++i ) {
        printf( "%i:\t%i\n", i, buckets[ i ] );
    }
    printf( "\n" );
}

inline int setBricks( int powerset, int row, int value ) {
    return powerset | ( value << 2 * ( C - row ) );
}

inline int getBricks( int powerset, int row ) {
    return ( powerset >> 2 * ( C - row ) ) & 4;
}

void fill( int prevpowerset, int currentpowerset, int j ) {
    if ( j == C ) {
        buckets[ currentpowerset ] += prevbuckets[ prevpowerset ];
        return;
    }
    int thisBricks = getBricks( prevpowerset, j );
    switch ( thisBricks ) {
        case 0:
            // prev: = =
            
            // this: =
            //       =
            //       =
            if ( j + 3 <= C
                 && getBricks( prevpowerset, j + 1 ) == 0
                 && getBricks( prevpowerset, j + 2 ) == 0 ) {
                fill(
                    prevpowerset,
                    setBricks(
                        setBricks(
                            setBricks(
                                currentpowerset,
                                j, 0
                            ), j + 1, 0
                        ), j + 2, 0
                    ), j + 3
                );
            }

            // this:
            //   =
            // = =
            if ( j + 2 <= C
                 && getBricks( prevpowerset, j + 1 ) == 1 ) {
                fill(
                    prevpowerset,
                    setBricks(
                        setBricks(
                            currentpowerset,
                            j, 0
                        ), j + 1, 0
                    ), j + 2
                );
            }
            break;
        case 3:
            // prev: _ _
            // this: = = = 
            fill(
                prevpowerset,
                setBricks(
                    currentpowerset,
                    j, 0
                ),
                j + 1
            );
            break;
        case 1:
            // prev: = _
            //
            // = =
            // = _
            if ( j != C - 1
                 && getBricks( prevpowerset, j + 1 ) == 1 ) {
                fill(
                    setBricks( prevpowerset, j + 1, 0 ),
                    setBricks( currentpowerset, j, 0 ),
                    j + 1
                );
            }
            // = _ 
            // = =
            if ( j != C - 1
                && getBricks( prevpowerset, j + 1 ) == 1 ) {
                fill(
                    prevpowerset,
                    setBricks(
                        setBricks(
                            currentpowerset, j, 1
                        ), j + 1, 0
                    ),
                    j + 2
                );
            }
            // = = 
            // _ =
            if ( j != C - 1
                 && getBricks( prevpowerset, j + 1 ) == 0 ) {
                fill(
                    prevpowerset,
                    setBricks(
                        setBricks(
                            currentpowerset, j, 0
                        ), j + 1, 0
                    ),
                    j + 2
                );
            }
    }
    if ( thisBricks != 3 ) {
        // this: _ 
        fill( prevpowerset, currentpowerset, j + 1 );
    }
}

void dynamic() {
    int* temp = prevbuckets;
    prevbuckets = buckets;
    buckets = temp;

    for ( int powerset = 0; powerset < powersets; ++powerset ) {
        fill( powerset, ( 1 << ( 2 * C ) ) - 1, 0 ); // 0xfff...f w/ 2c binary digits
    }
}

int main() {
    int i = 0;

    printf( "Number of powersets per induction step: %i\n", powersets );

    buckets = ( int* )malloc( powersets * sizeof( int ) );
    prevbuckets = ( int* )malloc( powersets * sizeof( int ) );

    for ( i = 0; i < powersets; ++i ) {
        buckets[ i ] = 0;
    }
    buckets[ 0 ] = 1;

    printBuckets();
    for ( i = 0; i < N; ++i ) {
        printf( "Populating powersets introducing column %i\n", i );
        dynamic();
    }
    printBuckets();

    printf( "%i", buckets[ 0 ] );

    return 0;
}
