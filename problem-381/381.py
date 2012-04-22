import euclidean

solution = 0
primes = [ 2, 3 ]
N = pow( 10, 8 )
for p in xrange( 5, N, 2 ):
    found = True
    for prime in primes:
        if p % prime == 0:
            found = False
            break
        if prime * prime > p:
            break
    if found:
        primes.append( p )
        s = fact = p - 1
        for k in range( p - 1, p - 5, -1 ):
            inv = euclidean.inverse( k, p )
            fact = ( fact * inv ) % p
            s = ( s + fact ) % p
        solution = solution + s
    if p % 100000 == 1:
        print "Progress: %i" % ( 100 * p / N )
print solution
