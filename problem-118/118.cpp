#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>
#include "miller-rabin.h"
#include <sys/types.h>
#include <time.h>

using namespace std;

const int DIGITS = 9;

void print_sec( int sec ) {
    int min_ = sec / 60;
    sec %= 60;

    int hour = min_ / 60;
    min_ %= 60;

    printf( "%d:%02d:%02d", hour, min_, sec );
}

int factorial( int n ) {
    int res = 1;

    for ( int i = 1; i <= n; ++i ) {
        res *= i;
    }
    return res;
}

int main() {
    time_t t1, t2;
    set< set< int > > found;
    
    time( &t1 );
    vector< int > permutation;

    for ( int i = 1; i <= DIGITS; ++i ) {
        permutation.push_back( i );
    }

    int maxbitmask = 1 << DIGITS - 1;

    int j = 0;
    int maxj = factorial( DIGITS );

    do {
        for ( int bitmask = 0; bitmask < maxbitmask; ++bitmask ) {
            set< int > l = set< int >();

            int cur = 0;
            int b = bitmask;
            for ( int i = 0; i < DIGITS; ++i ) {
                cur *= 10;
                cur += permutation[ i ];
                if ( b & 1 ) {
                    l.insert( cur );
                    cur = 0;
                }
                b >>= 1;
            }
            l.insert( cur );
            bool valid = true;
            for ( set< int >::iterator it = l.begin(); it != l.end(); ++it ) {
                if ( !isprime( *it, 20 ) ) {
                    valid = false;
                }
            }
            if ( valid ) {
                found.insert( l );
            }
        }
        ++j;
        if ( j % 1000 == 0 ) {
            // print "%i / %i..." % ( j, maxj );
            time( &t2 );

            int delta = ( ( int )t2 - t1 ) / ( float( j ) / float( maxj ) ) - ( ( int )t2 - t1 );
            printf( "\r" );
            print_sec( delta );
            printf( " remaining" );
            fflush( stdout );
        }
    } while ( next_permutation( permutation.begin(), permutation.end() ) );

    printf( "\n" );
    // for ( set< set< int > >::iterator it = found.begin(); it != found.end(); ++it ) {
    //     printf( "{ " );
    //     for ( set< int >::iterator jt = it->begin(); jt != it->end(); ++jt ) {
    //         printf( "%i, ", *jt );
    //     }
    //     printf( " }\n" );
    // }

    printf( "Solution: %i\n", ( int )found.size() );

    return 0;
}
