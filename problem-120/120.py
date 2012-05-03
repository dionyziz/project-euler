def r( a, n ):
    asq = a * a
    return ( pow( a - 1, n, asq ) + pow( a + 1, n, asq ) ) % asq

def rmax( a ):
    M = 0
    for n in xrange( 0, 3 * a ):
        M = max( M, r( a, n ) )
    return M

ret = 0
for a in xrange( 3, 1001 ):
    ret += rmax( a )

print( ret )
