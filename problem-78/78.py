def solve():
    MOD = 1000000
    T = [ [ 1 ] ]
    c = 1
    while True:
        d = 0
        T.append( [ 0 ] )
        for i in xrange( 1, c + 1 ):
            T[ c ].append( ( T[ c ][ i - 1 ] + T[ c - i ][ min( i, c - i ) ] ) % MOD )
        if c % 10000 == 0:
            print( "p(%i) = %i" % ( c, T[ c ][ i ] ) )
        if T[ c ][ i ] == 0:
            print( "p(%i) = %i" % ( c, T[ c ][ i ] ) )
            return
        c = c + 1
solve()
