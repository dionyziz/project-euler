#include <cstdio>
#include <cstdlib>
#include <set>

using namespace std;

// const int MAX_N = 10000000;
const int MAX_N = 100;
set< int > primes;

int getprimes() {
    int i = 0;
    primes.insert( 2 );
    primes.insert( 3 );

    int candidate = 5;
    while ( candidate < MAX_N ) {
        bool isprime = true;
        for ( set< int >::iterator it = primes.begin(); ( *it ) * ( *it ) <= candidate; ++it ) {
            int prime = *it;

            if ( candidate % prime == 0 ) {
                isprime = false;
                break;
            }
        }
        if ( isprime ) {
            primes.insert( candidate );
        }
        candidate += 2;
        ++i;
        if ( i % 10000 == 0 ) {
            printf( "\rGetting primes... %2.0f%%", 100 * ( float )candidate / MAX_N );
        }
    }
    printf( "\rGetting primes... 100%%\n\n" );
}

int main() {
    int i, j, k;
    int* phi;
    FILE* fi;

    getprimes();

    phi = ( int* )malloc( ( MAX_N + 1 ) * sizeof( int ) );

    phi[ 0 ] = 0;
    phi[ 1 ] = 1;

    for ( i = 2; i <= MAX_N; ++i ) {
        phi[ i ] = i - 1;
    }
    i = 0;
    for ( set< int >::iterator it = primes.begin(); it != primes.end(); ++it ) {
        int prime = *it;
        k = 0;
        for ( j = prime; j <= MAX_N; j += prime ) {
            phi[ j ] -= k;
            ++k;
        }
        ++i;
        if ( i % 100 == 0 ) {
            printf( "\r%f%%", 100 * ( float )i / MAX_N );
        }
    }
    printf( "\rCalculating phi... 100%%\n\n" );
    printf( "\n\nWriting data...\n" );

    fi = fopen( "phi.txt", "w" );
    for ( i = 1; i <= MAX_N; ++i ) {
        fprintf( fi, "%i\n", phi[ i ] );
    }
    fclose( fi );

    return 0;
}
