import gmpy

side = 333333334
solution = 0
for x in xrange( 2, side ):
    for ( a, b, c ) in [ ( x, x, x + 1 ), ( x, x, x - 1 ) ]:
        if c % 2 == 0:
            s = ( a + b + c ) / 2
            if gmpy.is_square( s * ( s - a ) * ( s - b ) * ( s - c ) ):
                solution = solution + a + b + c
    if x % 1000000 == 0:
        print "Progress: %i%%" % ( 100 * x / side )
print solution
