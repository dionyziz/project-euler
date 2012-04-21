from millerrabin import isPrime

def solve():
    GROUP_SIZE = 5
    primes = [ 2 ]
    groups = [ 0, [ [ 2 ] ], [], [], [], [] ]
    candidate = 3
    while True:
        # Sieve of Eratosthenes
        found = True
        for prime in primes:
            if candidate % prime == 0:
                found = False
                break
            if prime * prime > candidate:
                break
        if found:
            primes.append( candidate )
            groups[ 1 ].append( [ candidate ] )
            for cardinality in range( 1, GROUP_SIZE ):
                for group in groups[ cardinality ]:
                    if candidate in group:
                        continue
                    remarkable = True
                    for item in group:
                        a = int( str( candidate ) + str( item ) )
                        b = int( str( item ) + str( candidate ) )
                        if not isPrime( a ) or not isPrime( b ):
                           remarkable = False
                           break
                    if remarkable:
                        groups[ cardinality + 1 ].append( group + [ candidate ] )
                        if cardinality + 1 == GROUP_SIZE:
                            last = len( groups[ GROUP_SIZE ] ) - 1
                            print groups[ GROUP_SIZE ][ last ]
                            print 'Sum is %i' % ( sum( groups[ GROUP_SIZE ][ last ] ) )
                            return
        candidate = candidate + 2

solve()
