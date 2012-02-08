#include <cstdio>
#include <cmath>
#include <map>

using namespace std;

const int N = 10000;

struct iter {
    int m;
    int d;
    int a;
};

int operator <( iter a, iter b ) {
    if ( a.m != b.m ) {
        return a.m - b.m;
    }
    if ( a.d != b.d ) {
        return a.d - b.d;
    }
    return a.a - b.a;
}

iter makeIter( int m, int d, int a ) {
    iter ret;

    ret.m = m;
    ret.d = d;
    ret.a = a;

    return ret;
}

// calculates the length of the period of the continued fraction expansion of
// the square root of an integer s, providing s is not a perfect square
int continuedFractionLength( int s ) {
    map< iter, int > past;
    int i = 0, m = 0, d = 1, sq = sqrt( s );
    int a = floor( sq );

    do {
        // continued fraction expansion of irrational square root
        // see http://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Continued_fraction_expansion
        m = d * a - m;
        d = ( s - m * m ) / d;
        a = floor( ( sq + m ) / d );
        iter moment = makeIter( m, d, a );
        if ( past.find( moment ) != past.end() ) {
            return i - past[ moment ];
        }
        past[ moment ] = i;
        ++i;
    } while ( true );
}

int main() {
    int c;

    for ( int i = 2; i <= N; ++i ) {
        int sq = ( int )sqrt( i );
        if ( sq * sq != i ) {
            // irrational square root
            if ( continuedFractionLength( i ) % 2 == 1 ) {
                // odd continued fraction period
                ++c;
            }
        }
    }
    printf( "Solution: %i\n", c );

    return 0;
}
