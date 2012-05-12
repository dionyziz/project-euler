#include <cstdio>
#include <utility>

using namespace std;

const int N = 100;

pair< int, int > subset( int* A, int n, int bitmask ) {
    int a = 0, acnt = 0;

    for ( int i = 0, p = 1 << n; bitmask; ++i, p >>= 1, bitmask >>= 1 ) {
        if ( ( bitmask & 1 ) == 1 ) {
            a += A[ i ];
            ++acnt;
        }
    }
    return make_pair( a, acnt );
}

bool special( int* A, int n ) {
    int m = 1 << n;

    for ( int bitmask1 = 1; bitmask1 < m - 2; ++bitmask1 ) {
        pair< int, int > a = subset( A, n, bitmask1 );
        for ( int bitmask2 = bitmask1 + 1; bitmask2 < m - 1; ++bitmask2 ) {
            if ( bitmask1 & bitmask2 ) {
                continue;
            }
            pair< int, int > b = subset( A, n, bitmask2 );

            if ( a.first == b.first
            || ( a.second > b.second && a.first < b.first )
            || ( a.second < b.second && a.first > b.first ) ) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    FILE* fi = fopen( "sets.txt", "r" );
    int total = 0, i, a, sum, n, A[ 12 ];
    char c;

    for ( i = 0; i < N; ++i ) {
        sum = n = 0;
        do {
            fscanf( fi, "%i", &a );
            fscanf( fi, "%c", &c );
            A[ n ] = a;
            ++n;
            sum += a;
        } while ( c == ',' );
        if ( special( A, n ) ) {
            total += sum;
        }
    }
    printf( "%i\n", total );
    return 0;
}
