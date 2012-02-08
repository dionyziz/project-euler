#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <set>

const int L = 1500000;

using namespace std;

struct pythagorean {
    int a;
    int b;
    int c;
};

bool operator <( pythagorean a, pythagorean b ) {
    if ( a.a != b.a ) {
        return a.a - b.a < 0;
    }
    return a.b - b.b < 0;
}

int operator ==( pythagorean a, pythagorean b ) {
    return a.a == b.a && a.b == b.b;
}

pythagorean makePythagorean( int a, int b, int c ) {
    pythagorean ret;

    ret.a = a;
    ret.b = b;
    ret.c = c;

    return ret;
}

int main() {
    int c = 0;
    set< pythagorean >* triples;
    int maxM = ceil( sqrt( L ) );

    triples = ( set< pythagorean >* )malloc( ( L + 1 ) * sizeof( set< pythagorean > ) );

    for ( int i = 0; i <= L; ++i ) {
        triples[ i ] = set< pythagorean >();
    }

    for ( int m = 1; m <= maxM; ++m ) {
        for ( int n = 1; n < m; ++n ) {
            // Euclid's formula for Pythagorean triples
            int baseA = m * m - n * n;
            int baseB = 2 * m * n;
            int baseC = m * m + n * n;

            if ( baseA > baseB ) {
                int t = baseA;
                baseA = baseB;
                baseB = t;
            }

            for ( int k = 1; ; ++k ) {
                int a = k * baseA, b = k * baseB, c = k * baseC;
                int l = a + b + c;
                if ( l > L ) {
                    break;
                }
                assert( a <= b );
                triples[ l ].insert( makePythagorean( a, b, c ) );
            }
        }
        printf( "\rBuilding Pythagorean triples... %i%%...", 100 * m / maxM );
    }
    printf( "\rBuilding Pythagorean triples... %i%%...\n", 100 );

    for ( int l = 1; l <= L; ++l ) {
        if ( triples[ l ].size() == 1 ) {
            ++c;
        }
    }
    // int l = 287280;
    // printf( "Pythagorean triples with circumference %i: \n", l );
    // for ( set< pythagorean >::iterator it = triples[ l ].begin(); it != triples[ l ].end(); ++it ) {
    //     printf( "( %i, %i, %i )\n", it->a, it->b, it->c );
    // }

    printf( "Solution: %i\n", c );

    return 0;
}
