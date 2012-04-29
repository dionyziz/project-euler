#include <cstdio>
#include <algorithm>
#include <cmath>

typedef unsigned long long int lli;

using namespace std;

int main() {
    int range[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    lli M = 0;
    int j = 0;

    do {
        if ( j % 100000 == 0 ) {
            printf( "%i%%\n", 100 * j / 3628800 );
        }
        ++j;
        if ( range[ 0 ] > range[ 3 ]
          || range[ 0 ] > range[ 5 ]
          || range[ 0 ] > range[ 7 ]
          || range[ 0 ] > range[ 9 ] ) {
            // printf( "Non-minimal\n" );
            continue;
        }
        int s = range[ 0 ] + range[ 1 ] + range[ 2 ];
        if ( range[ 3 ] + range[ 2 ] + range[ 4 ] != s
          || range[ 5 ] + range[ 4 ] + range[ 6 ] != s
          || range[ 7 ] + range[ 6 ] + range[ 8 ] != s
          || range[ 9 ] + range[ 8 ] + range[ 1 ] ) {
            // printf( "Non-magic\n" );
            continue;
        }
        if ( m > M ) {
            printf( "%llu\n", m );
        }
    } while ( next_permutation( range, range + 10 ) );
    return 0;
}
