#include "millerrabin.h"

typedef unsigned long long int lli;

lli powMod( int a, int b, int p ) {
    // pow by repeated squaring
    lli r = 1, aa = a;

    while ( true ) {
        if ( b & 1 ) {
            r = r * aa % p;
        }
        b >>= 1;
        if ( b == 0 ) {
            break;
        }
        aa = ( aa * aa ) % p;
    }
    return r;
}

bool isPrime( int n ) {
    if ( n <= 3 || n == 7 ) {
        return true;
    }
    if ( n % 2 == 0 ) {
        return false;
    }
    int d = n - 1;
    int s = 0;
    while ( d % 2 == 0 ) {
        d = d / 2;
        ++s;
    }
    for ( int i = 0; i < 7; ++i ) {
        int a = 2 + rand() % ( n - 3 );
        lli x = powMod( a, d, n );
        // assert( x < n && x >= 0 );
        if ( x == 1 || x == n - 1 ) {
            continue;
        }
        bool prime = false;
        for ( int r = 1; r < s; ++r ) {
            x = ( x * x ) % n;
            if ( x == 1 ) {
                return false;
            }
            if ( x == n - 1 ) {
                prime = true;
                break;
            }
        }
        if ( !prime ) {
            return false;
        }
    }
    return true;
}
