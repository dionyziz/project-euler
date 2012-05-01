from copy import copy

def combine( A, B ):
    return ( abs( A - B ), A + B )

( s1, s2, s3 ) = ( 1, 2, 3 )
N = 5
S = { 0: 1 }
for i in range( 1, N + 1 ):
    Sp = copy( S )
    cnt = 0
    for s in S:
        ( m, M ) = combine( s, s1 )
        print( "Combining %i with %i to produce a minimum of %i and a maximum of %i" % ( s, s1, m, M ) )
        for j in range( m, M + 1 ):
            if j not in Sp:
                Sp[ j ] = 0
            Sp[ j ] = Sp[ j ] + 1
        cnt = cnt + M - m 
    print( Sp )
    print( "Count is %i" % ( cnt ) )
    S = Sp
    # print( "f( %i ) = %i" % ( i, cnt ) )
    ( s1, s2, s3 ) = ( s2, s3, s1 + s3 )
