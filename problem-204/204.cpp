#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

typedef unsigned long long int llu;

const llu N = 1000000000;
const int MAX_PRIME = 100;

int prime_cnt = 1;
llu primes[ MAX_PRIME ];

void eratosthenes() {
    primes[ 0 ] = 2;

    for ( llu candidate = 3; candidate < MAX_PRIME; candidate += 2 ) {
        bool prime = true;
        for ( int witness = 0;
              witness < prime_cnt
           && primes[ witness ] * primes[ witness ] <= candidate;
              ++witness ) {
            if ( candidate % primes[ witness ] == 0 ) {
                prime = false;
                break;
            }
        }
        if ( prime ) {
            primes[ prime_cnt++ ] = candidate;
        }
    }
}

inline llu value( vector< llu > factors ) {
    llu ret = 1;

    for ( int i = 0; i < prime_cnt; ++i ) {
        ret *= pow( primes[ i ], factors[ i ] );
    }

    return ret;
}

inline bool increment( vector< llu > &factors ) {
    for ( int i = 0; i < prime_cnt; ++i ) {
        ++factors[ i ];
        if ( value( factors ) <= N ) {
            return true;
        }
        factors[ i ] = 0;
    }
    return false;
}

int main() {
    eratosthenes();

    llu total = 0;
    vector< llu > factorization;

    for ( int i = 0; i < prime_cnt; ++i ) {
        factorization.push_back( 0 );
    }

    while ( increment( factorization ) ) {
        ++total;
    }

    printf( "%llu\n", total + 1 );

    return 0;
}
