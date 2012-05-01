#include <cstdio>
#include <cstdlib>
#include <list>
#include <queue>
#include <cassert>
#include <set>

using namespace std;

struct edge {
    int u;
    int v;
    int w;
};

bool operator <( edge e, edge f ) {
    return e.w > f.w;
}

int N;
vector< list< edge > > E;

edge makeEdge( int u, int v, int w ) {
    edge ret;

    ret.u = u;
    ret.v = v;
    ret.w = w;

    return ret;
}

int prim() {
    priority_queue< edge > q;
    set< int > visited;
    int i, j, cost = 0;
    edge e;

    for ( list< edge >::iterator it = E[ 0 ].begin(); it != E[ 0 ].end(); ++it ) {
        q.push( *it );
    }
    visited.insert( 0 );
    while ( !q.empty() ) {
        e = q.top();
        q.pop();
        if ( visited.find( e.v ) == visited.end() ) {
            cost += e.w;
            visited.insert( e.v );
            for ( list< edge >::iterator it = E[ e.v ].begin(); it != E[ e.v ].end(); ++it ) {
                q.push( *it );
            }
        }
    }

    return cost;
}

int main() {
    FILE* in = fopen( "network.txt", "r" );
    int i, u, v, M, w, oldcost = 0, newcost = 0;

    fscanf( in, "%i", &N );

    for ( i = 0; i < N; ++i ) {
        E.push_back( list< edge >() );
    }
    
    for ( u = 0; u < N; ++u ) {
        for ( v = 0; v < N; ++v ) {
            fscanf( in, "%i", &w );
            if ( v != N - 1 ) {
                fscanf( in, "," );
            }
            if ( w > -1 ) {
                oldcost += w;
                E[ u ].push_back( makeEdge( u, v, w ) );
            }
        }
    }
    oldcost /= 2;
    newcost = prim();
    printf( "Original cost: %i\n", oldcost );
    printf( "MST cost: %i\n", newcost );
    printf( "Solution: %i\n", oldcost - newcost );

    return 0;
}
