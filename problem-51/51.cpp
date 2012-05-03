#include <cstdio>
#include <map>
#include <cassert>
#include <cstring>
#include <vector>
#include <list>

using namespace std;

int delta( int a, int b ) {
    char firsta = 0, firstb = 0;
    char stra[ 20 ], strb[ 20 ];

    sprintf( stra, "%i", a );
    sprintf( strb, "%i", b );
    
    int la = strlen( stra ), lb = strlen( strb );

    if ( la != lb ) {
        return 0;
    }
    int exp = 1;
    int tuple = 0;
    for ( int i = 0; i < la; ++i ) {
        if ( stra[ i ] != strb[ i ] ) {
            if ( firsta == 0 ) {
                firsta = stra[ i ];
                firstb = strb[ i ];
            }
            if ( stra[ i ] != firsta || strb[ i ] != firstb ) {
                return 0;
            }
            tuple += exp;
        }
        exp *= 2;
    }
    return tuple;
}

int main() {
    int primeCnt = 1;
    vector< int > primes;
    map< int, map< int, list< int > > > groups;

    primes.push_back( 2 );
    groups[ 2 ] = map< int, list< int > >();
   
    for ( int candidate = 3; ; candidate += 2 ) {
        bool prime = true;
        for ( vector< int >::iterator witness = primes.begin(); witness < primes.end(); ++witness ) {
            if ( candidate % *witness == 0 ) {
                prime = false;
                break;
            }
            if ( *witness * *witness > candidate ) {
                break;
            }
        }
        if ( prime ) {
            for ( vector< int >::iterator neighbour = primes.begin(); neighbour < primes.end(); ++neighbour ) {
                int d = delta( candidate, *neighbour );
                if ( d ) {
                    if ( groups.find( *neighbour ) == groups.end() ) {
                        groups[ *neighbour ] = map< int, list< int > >();
                    }
                    if ( groups[ *neighbour ].find( d ) == groups[ *neighbour ].end() ) {
                        groups[ *neighbour ][ d ] = list< int >();
                    }
                    groups[ *neighbour ][ d ].push_back( candidate );
                    if ( groups[ *neighbour ][ d ].size() > 6 ) {
                        printf( "%i\n", *neighbour );
                        for ( list< int >::iterator it = groups[ *neighbour ][ d ].begin(); it != groups[ *neighbour ][ d ].end(); ++it ) {
                            printf( "%i\n", *it );
                        }
                        return 0;
                    }
                }
            }
            primes.push_back( candidate );
            ++primeCnt;
        }
        if ( candidate % 1000 == 1 ) {
            printf( "Searching: %i...\n", candidate );
        }
    }
    return 1;
}
