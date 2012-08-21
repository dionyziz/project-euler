#include <cstdio>
#include <sys/types.h>
#include <time.h>

using namespace std;

typedef unsigned long long int llu;

const llu MAX_PRIME = 120000;
llu primes[ MAX_PRIME ];
llu rad[ MAX_PRIME ];
llu prime_cnt;

void print_sec( int sec ) {
    int min_ = sec / 60;
    sec %= 60;

    int hour = min_ / 60;
    min_ %= 60;

    printf( "%d:%02d:%02d", hour, min_, sec );
}

llu gcd( llu a, llu b ) {
    if ( b == 0 ) {
        return a;
    }
    return gcd( b, a % b );
}

void eratosthenes() {
    for ( llu candidate = 1; candidate < MAX_PRIME; ++candidate ) {
        rad[ candidate ] = 1;
    }

    for ( llu candidate = 2; candidate < MAX_PRIME; ++candidate ) {
        bool prime = true;

        for ( llu witness = 0; witness < prime_cnt; ++witness ) {
            if ( primes[ witness ] * primes[ witness ] > candidate ) {
                break;
            }
            if ( candidate % primes[ witness ] == 0 ) {
                prime = false;
                break;
            }
        }
        if ( prime ) {
            primes[ prime_cnt++ ] = candidate;

            for ( llu mul = candidate; mul < MAX_PRIME; mul += candidate ) {
                rad[ mul ] *= candidate;
            }
        }
    }
}

int main() {
    llu sigma = 0;
    llu cnt = 0;

    prime_cnt = 0;

    printf( "Evaluating radicals... " );
    fflush( stdout );

    eratosthenes();

    printf( "Done\n" );

    printf( "Looking for hits... " );
    fflush( stdout );

    time_t t1, t2;

    time( &t1 );

    for ( llu a = 1; a < MAX_PRIME - 1; ++a ) {
        for ( llu b = a + 1, c = a + b; c < MAX_PRIME; ++b, c = a + b ) {
            if ( gcd( a, b ) == 1 && gcd( a, c ) == 1 && gcd( b, c ) == 1 ) {
                llu radabc = ( llu )rad[ a ] * ( llu )rad[ b ] * ( llu )rad[ c ];

                if ( radabc < c ) {
                    ++cnt;
                    sigma += c;
                }
            }
        }
        if ( a % 10 == 0 ) {
            time( &t2 );

            int delta = ( ( int )t2 - t1 ) / ( float( a ) / float( MAX_PRIME ) ) - ( ( int )t2 - t1 );
            printf( "\rLooking for hits... " );
            print_sec( delta );
            printf( " remaining" );
            fflush( stdout );
        }
    }
    printf( "\n" );

    printf( "Found %llu hits with sum = %llu\n", cnt, sigma );

    return 0;
}
