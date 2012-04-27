#include "euclidean.h"

using namespace std;

typedef unsigned long long int lli;

void extended( int a, int b, int* s, int* t ) {
    lli x = 0, y = 1, lastx = 1, lasty = 0, q, temp;

    while ( b != 0 ) {
        q = a / b;
        temp = b;
        b = a % b;
        a = temp;
        temp = x;
        x = lastx - q * x;
        lastx = temp;
        temp = y;
        y = lasty - q * y;
        lasty = temp;
    }
    *s = lastx;
    *t = lasty;
}

int inverse( int a, int p ) {
    int s, t;

    extended( a, p, &s, &t );
    return ( p + s ) % p;
}
