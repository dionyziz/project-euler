#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int N = 1000;

struct fraction {
    int n;
    int d;
};

vector< int > primes;

inline bool operator < ( fraction a, fraction b ) {
    return ( long long )a.n * b.d - ( long long )b.n * a.d < 0;
}

inline fraction make( int n, int d ) {
    fraction f;

    f.n = n; f.d = d;

    return f;
}

void generatePrimes() {
    bool isPrime;

    primes.push_back( 2 );

    for ( int i = 3; i < N; i += 2 ) {
        isPrime = true;
        for ( vector< int >::iterator it = primes.begin(); it != primes.end() && ( *it ) * ( *it ) <= i; ++it ) {
            if ( i % *it == 0 ) {
                isPrime = false;
                break;
            }
        }
        if ( isPrime ) {
            primes.push_back( i );
        }
    }
}

inline bool reduced( fraction f ) {
    for ( vector< int >::iterator it = primes.begin(); it != primes.end() && *it <= f.n; ++it ) {
        if ( f.n % *it == 0 && f.d % *it == 0 ) {
            return false;
        }
    }
    return true;
}

int main( int argc, char* argv[] ) {
    long long int c = 0;
    fraction f;

    N = atoi( argv[ 1 ] );

    // printf( "Generating primes...\n" );
    generatePrimes();

    for ( int n = 1; n <= N; ++n ) {
        if ( n % 1000 == 0 ) {
            printf( "%2.2f%%...\n", ( float )( 100 * n ) / N );
        }
        for ( int d = n + 1; d <= N; ++d ) {
            f = make( n, d );
            if ( reduced( f ) ) {
                c++;
            }
        }
    }
    // printf( "\n" );
    printf( "%i\n", c );
    return 0;
}
