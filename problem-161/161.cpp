#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

typedef unsigned long long int LL;

struct shape {
    int s;
    int j;
};

const int SHAPE_I = 1;
const int SHAPE_DASH = 2;
const int SHAPE_L = 3;
const int SHAPE_MIRRORL = 4;
const int SHAPE_GAMMA = 5;
const int SHAPE_MIRRORGAMMA = 6;

int C = 9, N = 12;
LL powersets = 1 << ( 2 * C );
LL prevpowersetcount;
int prevpowersetUntouched;
int inductionStep;
LL* prevbuckets;
LL* buckets;

shape make_shape( int j, int s ) {
    shape ret;

    if ( s == 0 ) {
        printf( "OMG! GENREAL FAILURE!\n" );
    }

    ret.s = s;
    ret.j = j;

    return ret;
}

void printBinary( int n ) {
    int i, j = 0;

    for ( i = powersets >> 1; i; i = i >> 1 ) {
        printf( "%i", !!( n & i ) );
        ++j;
        if ( j % 2 == 0 ) {
            printf( " " );
        }
    }
}

void printBuckets() {
    int i;
    for ( i = 0; i < powersets; ++i ) {
        if ( buckets[ i ] ) {
            printBinary( i );
            printf( ":\t%i\n", buckets[ i ] );
        }
    }
    printf( "\n" );
}

inline int setBricks( int powerset, int row, int value ) {
    return powerset
           & ~( 3 << 2 * ( C - 1 - row ) )
           | ( value << 2 * ( C - 1 - row ) );
}

inline int getBricks( int powerset, int row ) {
    return ( powerset >> 2 * ( C - 1 - row ) ) & 3;
}

void printShapes( stack< shape > s ) {
    while ( !s.empty() ) {
        shape sh = s.top();
        switch ( sh.s ) {
            case SHAPE_L:
                printf( "L " );
                break;
            case SHAPE_GAMMA:
                printf( "|-" );
                break;
            case SHAPE_MIRRORL:
                printf( "_|" );
                break;
            case SHAPE_MIRRORGAMMA:
                printf( "-|" );
                break;
            case SHAPE_I:
                printf( "| " );
                break;
            case SHAPE_DASH:
                printf( "_ " );
                break;
            default:
                printf( "ALARM! ALARM! ALARM! %i\n", sh.s );
        }
        printf( "@%i\t", sh.j );
        s.pop();
    }
    printf( "\n" );
}

void fill( int prevpowerset, int currentpowerset, int j ) { // , stack< shape > s ) {
    if ( j == C ) {
        buckets[ currentpowerset ] += prevpowersetcount;
        // if ( currentpowerset == 0 && inductionStep == N - 1 ) {
        //     printBinary( prevpowersetUntouched );
        //     printf( " -> " );
        //     printBinary( currentpowerset );
        //     printf( ":\n" );
        //     printShapes( s );
        // }
        return;
    }
    // printf( "Fill called for row %i\n", j );
    int thisBricks = getBricks( prevpowerset, j );
    switch ( thisBricks ) {
        case 0:
            // prev: = =
            
            // this: =
            //       =
            //       =
            if ( j + 3 <= C
                 && getBricks( prevpowerset, j + 1 ) == 0 ) {
                if ( getBricks( prevpowerset, j + 2 ) == 0 ) {
                    // s.push( make_shape( j, SHAPE_I ) );
                    fill(
                        prevpowerset,
                        setBricks(
                            setBricks(
                                setBricks(
                                    currentpowerset,
                                    j, 0
                                ), j + 1, 0
                            ), j + 2, 0
                        ), j + 3 // , s
                    );
                    // s.pop();
                }
                else if (    getBricks( prevpowerset, j + 2 ) == 1 && j + 4 <= C
                          && getBricks( prevpowerset, j + 3 ) == 1 ) {
                    // s.push( make_shape( j, SHAPE_I ) );
                    // s.push( make_shape( j + 3, SHAPE_L ) );
                    fill(
                        prevpowerset,
                        setBricks(
                            setBricks(
                                setBricks(
                                    setBricks(
                                        currentpowerset,
                                        j, 0
                                    ), j + 1, 0
                                ), j + 2, 0
                            ), j + 3, 0
                        ), j + 4 // , s
                    );
                    // s.pop();
                    // s.pop();
                }
            }

            // this:
            //   =
            // = =
            if ( j + 2 <= C
                 && getBricks( prevpowerset, j + 1 ) == 1 ) {
                // s.push( make_shape( j, SHAPE_MIRRORL ) );
                fill(
                    prevpowerset,
                    setBricks(
                        setBricks(
                            currentpowerset,
                            j, 0
                        ), j + 1, 0
                    ), j + 2 // , s
                );
                // s.pop();
            }
            break;
        case 3:
            // prev: _ _
            // this: = = = 
            // s.push( make_shape( j, SHAPE_DASH ) );
            fill(
                prevpowerset,
                setBricks(
                    currentpowerset,
                    j, 0
                ), j + 1 // , s
            );
            // s.pop();
            break;
        case 1:
            // prev: = _
            //
            // = =
            // = _
            if ( j + 2 <= C
                 && getBricks( prevpowerset, j + 1 ) == 1 ) {
                // s.push( make_shape( j, SHAPE_GAMMA ) );
                fill(
                    setBricks( prevpowerset, j + 1, 0 ),
                    setBricks( currentpowerset, j, 0 ),
                    j + 1 // , s
                );
                // s.pop();
            }
            // = _ 
            // = =
            if ( j + 2 <= C
                && getBricks( prevpowerset, j + 1 ) == 1 ) {
                // s.push( make_shape( j, SHAPE_L ) );
                fill(
                    prevpowerset,
                    setBricks(
                        setBricks(
                            currentpowerset, j, 1
                        ), j + 1, 0
                    ), j + 2 // , s
                );
                // s.pop();
            }
            // = = 
            // _ =
            if ( j + 2 <= C ) {
                switch ( getBricks( prevpowerset, j + 1 ) ) {
                    case 0:
                        // s.push( make_shape( j, SHAPE_MIRRORGAMMA ) );
                        fill(
                            prevpowerset,
                            setBricks(
                                setBricks(
                                    currentpowerset, j, 0
                                ), j + 1, 0
                            ), j + 2 // , s
                        );
                        // s.pop();
                        break;
                    case 1:
                        if ( j + 3 <= C && getBricks( prevpowerset, j + 2 ) == 1 ) {
                            // s.push( make_shape( j, SHAPE_MIRRORGAMMA ) );
                            // s.push( make_shape( j + 1, SHAPE_L ) );
                            fill(
                                prevpowerset,
                                setBricks(
                                    setBricks(
                                        setBricks(
                                            currentpowerset, j, 0
                                        ), j + 1, 0
                                    ), j + 2, 0
                                ), j + 3 // , s
                            );
                            // s.pop();
                            // s.pop();
                        }
                        break;
                }
            }
    }
    if ( thisBricks != 3 ) {
        // this: _ 
        fill(
            prevpowerset,
            setBricks(
                currentpowerset, j, thisBricks == 1? 3: 1
            ), j + 1 // , s
        );
    }
}

void dynamic() {
    LL* temp = prevbuckets;
    prevbuckets = buckets;
    buckets = temp;

    for ( int powerset = 0; powerset < powersets; ++powerset ) {
        buckets[ powerset ] = 0;
    }

    for ( int powerset = 0; powerset < powersets; ++powerset ) {
        prevpowersetUntouched = powerset;
        prevpowersetcount = prevbuckets[ powerset ];
        if ( prevpowersetcount ) {
            // printf( "Applying dynamic programming on previous powerset: " );
            // printBinary( powerset );
            fill( powerset, ( 1 << ( 2 * C ) ) - 1, 0 ); // , stack< shape >() ); // 0xfff...f w/ 2c binary digits
        }
    }
}

int main() {
    int i = 0;

    printf( "Number of powersets per induction step: %i\n", powersets );

    buckets = ( LL* )malloc( powersets * sizeof( LL ) );
    prevbuckets = ( LL* )malloc( powersets * sizeof( LL ) );

    for ( i = 0; i < powersets; ++i ) {
        buckets[ i ] = 0;
    }
    buckets[ 0 ] = 1;

    // printBuckets();
    for ( inductionStep = 0; inductionStep < N; ++inductionStep ) {
        printf( "Populating powersets introducing column %i\n", inductionStep );
        dynamic();
        printf( "Solution for column %i: %lli\n", inductionStep, buckets[ 0 ] );
        // printBuckets();
    }

    printf( "Final solution: %lli\n", buckets[ 0 ] );

    return 0;
}
