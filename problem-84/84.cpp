#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

const int DICE_SIDES = 4;
const int MONTE_CARLO = 100000000;

int probabilities[ 40 ];

enum monopoly {
    GO   = 0,  CC1 = 2,  R1 = 5,  CH1 = 7,
    JAIL = 10, C1  = 11, U1 = 12, R2  = 15, CC2 = 17,
    CH2  = 22, E3  = 24, R3 = 25, U2  = 28,
    G2J  = 30, CC3 = 33, R4 = 35, CH3 = 36, H2  = 39
};

int play( int current, int a, int b ) {
    static int cc = -1, ch = -1;

    current = ( current + a + b ) % 40;
    switch ( current ) {
        case G2J: return JAIL;
        case CC1: case CC2: case CC3:
            cc = ( cc + 1 ) % 16;
            switch ( cc ) {
                case 0: return GO;
                case 1: return JAIL;
            }
            break;
        case CH1: case CH2: case CH3:
            ch = ( ch + 1 ) % 16;
            switch ( ch ) {
                case 0: return GO;
                case 1: return JAIL;
                case 2: return C1;
                case 3: return E3;
                case 4: return H2;
                case 5: return R1;
                case 6: case 7:
                    switch ( current ) {
                        case CH1: return R2;
                        case CH2: return R3;
                        case CH3: return R1;
                    }
                    break;
                case 8:
                    switch ( current ) {
                        case CH1: case CH3: return U1;
                        case CH2:           return U2;
                    }
                    break;
                case 9:
                    return play( current - 3, 0, 0 );
            }
            break;
    }
    return current;
}

int main() {
    int current = GO, maxelement;

    srand( time( NULL ) );
    for ( int plays = 0; plays < MONTE_CARLO; ++plays ) {
        current = play( current, 1 + rand() % DICE_SIDES, 1 + rand() % DICE_SIDES );
        ++probabilities[ current ];
    }
    for ( int j = 0; j < 3; ++j ) {
        for ( int i = 0, m = 0; i < 40; ++i ) {
            if ( m < probabilities[ i ] ) {
                m = probabilities[ i ];
                maxelement = i;
            }
        }
        printf( "P( %i ) = %2.5f\n", maxelement, ( float )probabilities[ maxelement ] / plays );
        probabilities[ maxelement ] = 0;
    }

    return 0;
}
