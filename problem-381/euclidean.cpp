#include "euclidean.h"

pair< int, int > extended( int a, int b ) {
    if ( b == 0 ) {
        return make_pair( 1, 0 );
    }
    pair< int, int > p = extended( b, a % b );
    int s = p.first;
    int t = p.second;
    return make_pair( t, s - ( a / b ) * t );
}

int inverse( int a, int p ) {
    return ( p + extended( a, p ).first ) % p;
}
