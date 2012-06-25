#include <cstdio>

using namespace std;

const int N = 1000;

int main() {
    int sum = 0;

    for ( int i = 0; i < N; ++i ) {
        if ( i % 3 == 0 || i % 5 == 0 ) {
            sum += i;
        }
    }
    printf( "%i\n", sum );

    return 0;
}
