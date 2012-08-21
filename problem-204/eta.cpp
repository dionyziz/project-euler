/*
 * Simple ETA library for project euler
 * MIT licensed
 *
 * Dionysis "dionyziz" Zindros <dionyziz@gmail.com>
 */
#include "eta.h"
#include <cstdio>
#include <cassert>

const float EPSILON = 0.0001;

ETA::ETA() {
    reset();
}

void ETA::reset() {
    time( &t1 );
}

void ETA::get( float completed, int &h, int &m, int &s ) {
    time_t t2;
    time( &t2 );

    assert( completed > 0 );

    int diff = ( int )t2 - t1;

    s = ( int )( ( float )diff / completed - diff );
    // printf( "Total time in seconds: %i\n", s );

    m = s / 60;
    s %= 60;

    h = m / 60;
    m %= 60;
}

void ETA::print( float completed ) {
    int h, m, s;

    if ( completed < EPSILON ) {
        printf( "∞" );
    }
    else {
        get( completed, h, m, s );
        printf( "%d:%02d:%02d", h, m, s );
    }
    fflush( stdout );
}
