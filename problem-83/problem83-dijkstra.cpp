#include <cstdio>
#include <queue>

using namespace std;

const int N = 80;

struct Node {
    int i;
    int j;
    int w;
};

bool operator <( Node a, Node b ) {
    return a.w > b.w;
}

int C[ N ][ N ];
bool visited[ N ][ N ];
priority_queue< Node > q;

Node makeNode( int i, int j, int w ) {
    Node ret;

    ret.i = i;
    ret.j = j;
    ret.w = w;

    return ret;
}

void visit( int i, int j, int w ) {
    if ( i < 0 || i >= N || j < 0 || j >= N || visited[ i ][ j ] ) {
        return;
    }
    q.push( makeNode( i, j, w + C[ i ][ j ] ) );
    visited[ i ][ j ] = true;
}

int main() {
    FILE* fi = fopen( "problem83.in", "r" );
    Node node;
    int i, j;

    for ( i = 0; i < N; ++i ) {
        for ( j = 0; j < N; ++j ) {
            fscanf( fi, "%i,", &C[ i ][ j ] );
        }
    }
    q.push( makeNode( 0, 0, C[ 0 ][ 0 ] ) );

    while ( !q.empty() ) {
        node = q.top();
        if ( node.i == N - 1 && node.j == N - 1 ) {
            break;
        }
        visit( node.i + 1, node.j, node.w );
        visit( node.i - 1, node.j, node.w );
        visit( node.i, node.j + 1, node.w );
        visit( node.i, node.j - 1, node.w );
        q.pop();
    }

    printf( "Solution: %i\n", node.w );

    return 0;
}
