/*
 * Simple ETA library for project euler
 * MIT licensed
 *
 * Dionysis "dionyziz" Zindros <dionyziz@gmail.com>
 */
#ifndef ETA_H
#define ETA_H

#include <sys/types.h>
#include <time.h>

class ETA {
    public:
        ETA();
        void reset();
        void get( float, int &, int &, int & );
        void print( float );
    
    private:
        time_t t1;
};

#endif
