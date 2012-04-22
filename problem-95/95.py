N = 1000000
sumdiv = [ 0 ] * ( N + 1 )
for d in xrange( 1, N ):
    for p in xrange( 2 * d, N + 1, d ):
        sumdiv[ p ] = sumdiv[ p ] + d
    if d % 1000 == 0:
        print "Divisors: %i%%" % ( 100 * d / N )

maxlen = 0
for i in xrange( 1, N + 1 ):
    chain = set( [ i ] )
    cur = sumdiv[ i ]
    length = 1
    while cur not in chain:
        chain.add( cur )
        if cur > N:
            cur = -1
            break
        cur = sumdiv[ cur ]
        length = length + 1
    if cur == i:
        if length > maxlen:
            maxlen = length
            print chain
