#include <cstdio>
#include <set>

using namespace std;

int T[ 80 ];
int W[ 80 ][ 80 ];

int main() {
    set< int > primes;

    W[ 0 ][ 0 ] = 1;

    for ( int candidate = 2; ; ++candidate ) {
        bool prime = true;
        for ( set< int >::iterator it = primes.begin(); it != primes.end(); ++it ) {
            if ( candidate % *it == 0 ) {
                prime = false;
                break;
            }
            if ( *it * *it > candidate ) {
                break;
            }
        }
        if ( prime ) {
            primes.insert( candidate );
        }
        int i = 1;
        for ( set< int >::iterator it = primes.begin(); it != primes.end(); ++it, ++i ) {
            int d = W[ candidate - *it ][ 0 ];
            int j = 1;

            for ( set< int >::iterator jt = primes.begin(); jt != primes.end() && *jt <= *it; ++jt, ++j ) {
                d += W[ candidate - *it ][ j ];
            }
            W[ candidate ][ i ] = d;
            // printf( "W[ %i ][ %i ] = %i\n", candidate, i, W[ candidate ][ i ] );
            if ( ( T[ candidate ] += d ) > 5000 ) {
                printf( "%i\n", candidate );
                return 0;
            }
        }
    }

    return 0;
}
