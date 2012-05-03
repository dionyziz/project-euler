#include <cstdio>
#include <set>
#include <map>
#include <list>

using namespace std;

const int N = 100001;

int* primes = new int[ N ];
int* primeFactor = new int[ N ];
int primeCnt = 0;

void sieve() {
    for ( int candidate = 2; candidate < N; ++candidate ) {
        bool prime = true;
        for ( int i = 0; i < primeCnt; ++i ) {
            int witness = primes[ i ];
            if ( candidate % witness == 0 ) {
                prime = false;
                break;
            }
            if ( witness * witness > candidate ) {
                break;
            }
        }
        if ( prime ) {
            primes[ primeCnt++ ] = candidate;
            for ( int factor = 1; factor <= N / candidate; ++factor ) {
                primeFactor[ factor * candidate ] = candidate;
            }
        }
    }
}

int main() {
    int* rad = new int[ N ];
    map< int, list< int > > invRad;

    sieve();

    rad[ 1 ] = 1;
    invRad[ 1 ] = list< int >( 1, 1 );
    for ( int i = 2; i < N; ++i ) {
        int j = i;
        set< int > seen = set< int >();
        rad[ i ] = 1;
        while ( j > 1 ) {
            if ( seen.find( primeFactor[ j ] ) == seen.end() ) {
                rad[ i ] *= primeFactor[ j ];
                seen.insert( primeFactor[ j ] );
            }
            j /= primeFactor[ j ];
        }
        if ( invRad.find( rad[ i ] ) == invRad.end() ) {
            invRad[ rad[ i ] ] = list< int >();
        }
        invRad[ rad[ i ] ].push_back( i );
    }
    int e = 1;
    for ( map< int, list< int > >::iterator it = invRad.begin(); it != invRad.end(); ++it ) {
        for ( list< int >::iterator jt = it->second.begin(); jt != it->second.end(); ++jt ) {
            // printf( "E( %i ) = %i\n", e, *jt );
            if ( e == 10000 ) {
                printf( "E( 10000 ) = %i\n", *jt );
                return 0;
            }
            ++e;
        }
    }
    return 1;
}
