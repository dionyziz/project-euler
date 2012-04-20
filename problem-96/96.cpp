#include <cassert>
#include <cstdio>

using namespace std;

bool check( int sudoku[ 9 ][ 9 ], int row, int col ) {
    for ( int i = 0; i < 9; ++i ) {
        int p = 3 * ( row / 3 ) + i % 3, q = 3 * ( col / 3 ) + i / 3;
        if ( i != row && sudoku[ i ][ col ] == sudoku[ row ][ col ] // col
          || i != col && sudoku[ row ][ i ] == sudoku[ row ][ col ] // row
          || ( p != row || q != col ) && sudoku[ p ][ q ] == sudoku[ row ][ col ] ) { // box
            return false;
        }
    }
    return true;
}

bool solve( int sudoku[ 9 ][ 9 ], int row, int col ) {
    bool complete = false;
    int i, j = col;

    for ( i = row; i < 9; ++i ) {
        for ( ; j < 9; ++j ) {
            if ( sudoku[ i ][ j ] == 0 ) {
                int nextcol = ( j + 1 ) % 9, nextrow = i;
                if ( nextcol == 0 ) {
                    nextrow = i + 1;
                    complete = nextrow == 9;
                }
                for ( int v = 1; v <= 9; ++v ) {
                    sudoku[ i ][ j ] = v;
                    // backtracking prune
                    if ( check( sudoku, i, j ) ) {
                        if ( complete || solve( sudoku, nextrow, nextcol ) ) {
                            return true;
                        }
                    }
                }
                sudoku[ i ][ j ] = 0;
                return false;
            }
        }
        j = 0;
    }
    return true;
}

int main() {
    char c;
    int sudoku[ 9 ][ 9 ], sum = 0;
    FILE* in = fopen( "sudoku.txt", "r" );

    while ( !feof( in ) ) {
        fscanf( in, "Grid %*c%*c\n" );
        for ( int row = 0; row < 9; ++row ) {
            for ( int col = 0; col < 9; ++col ) {
                fscanf( in, "%c", &c );
                sudoku[ row ][ col ] = c - '0';
            }
            fscanf( in, "\n" );
        }
        solve( sudoku, 0, 0 );
        sum += 100 * sudoku[ 0 ][ 0 ] + 10 * sudoku[ 0 ][ 1 ] + sudoku[ 0 ][ 2 ];
    }
    printf( "Solution: %i\n", sum );

    return 0;
}
