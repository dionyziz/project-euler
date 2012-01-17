#include <map>
#include <set>
#include <list>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector< multimap< int, int > > polygonal;

int getPolygonal( int b, int n ) {
    switch ( b ) {
        case 3:
            return n * ( n + 1 ) / 2;
        case 4:
            return n * n;
        case 5:
            return n * ( 3 * n - 1 ) / 2;
        case 6:
            return n * ( 2 * n - 1 );
        case 7:
            return n * ( 5 * n - 3 ) / 2;
        case 8:
            return n * ( 3 * n - 2 );
    }
}

void build( int b ) {
    int n = 1;

    while ( true ) {
        int p = getPolygonal( b, n );
        if ( p < 1000 ) {
            ++n;
            continue;
        }
        if ( p > 9999 ) {
            break;
        }
        polygonal[ b ].insert( make_pair( p / 100, p ) );
        ++n;
    }
}

void printChain( list< int > chain ) {
    for ( list< int >::iterator i = chain.begin(); i != chain.end(); ++i ) {
        printf( "-> %i", *i );
    }
    printf( "\n" );
}

int main() {
    int p, n, b;
    int orderArr[ 6 ] = { 3, 4, 5, 6, 7, 8 };
    vector< int > order( orderArr, orderArr + 6 );

    polygonal.resize( 9 );

    for ( int b = 3; b <= 8; ++b ) {
        build( b );
    }

    do {
        // printf( "Checking order:\n" );
        // for ( vector< int >::iterator bi = order.begin(); bi != order.end(); ++bi ) {
        //     printf( "-/ %i", *bi );
        // }
        // printf( "\n\n" );

        set< list< int > > chains;

        chains.clear();
        int step;

        step = 0;
        for ( vector< int >::iterator bi = order.begin(); bi != order.end(); ++bi, ++step ) {
            bool updated = false;

            if ( bi == order.begin() ) {
                for ( multimap< int, int >::iterator ni = polygonal[ *bi ].begin(); ni != polygonal[ *bi ].end(); ++ni ) {
                    list< int > l;
                    l.push_back( ni->second );
                    chains.insert( l );
                    // printChain( l );
                }
                updated = true;
            }
            else {
                for ( set< list< int > >::iterator chain = chains.begin(); chain != chains.end(); ++chain ) {
                    if ( chain->size() == step ) {
                        pair< multimap< int, int >::iterator, multimap< int, int >::iterator > range = polygonal[ *bi ].equal_range( chain->back() % 100 );
                        for ( multimap< int, int >::iterator ni = range.first; ni != range.second; ++ni ) {
                            // printf( "%i -> %i\n", *chain->end(), ni->second );
                            list< int > l = *chain;
                            l.push_back( ni->second );
                            chains.insert( l );
                            updated = true;
                        }
                        // chains.erase( chain++ );
                    }
                }
            }
            // printf( "Valid chains after processing %i-agonal numbers: ", *bi );
            // for ( set< list< int > >::iterator chain = chains.begin(); chain != chains.end(); ++chain ) {
            //     printChain( *chain );
            // }
            // printf( "\n" );
        }
        for ( set< list< int > >::iterator chain = chains.begin(); chain != chains.end(); ++chain ) {
            if ( chain->front() / 100 == chain->back() % 100 && chain->size() == 6 ) {
                printf( "Got it! The order is:\n" );
                for ( vector< int >::iterator bi = order.begin(); bi != order.end(); ++bi ) {
                    printf( "-/ %i", *bi );
                }
                printf( "\nThe chain is:\n" );
                printChain( *chain );
                // return 0;
            }
        }
    } while ( next_permutation( order.begin(), order.end() ) );
    
    return 0;
}
