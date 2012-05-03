def delta( a, b ):
    if len( a ) != len( b ):
        return None
    idd = [ i for i in xrange( 0, len( a ) ) if a[ i ] != b[ i ] ]
    if len( idd ) == 0:
        return tuple( [] )
    ad = [ a[ i ] for i in idd ]
    bd = [ b[ i ] for i in idd ]
    same = lambda l: reduce( lambda acc, x: acc and x == l[ 0 ], l, True )
    if same( ad ) and same( bd ):
        return tuple( idd )
    return None

def solve():
    primes = [ 2 ]
    groups = { 2: {} }
    candidate = 3
    while len( primes ) < 10000:
        prime = True
        for witness in primes:
            if candidate % witness == 0:
                prime = False
                break
            if witness * witness > candidate:
                break
        if prime:
            scandidate = str( candidate )
            for neighbour in primes:
                d = delta( scandidate, str( neighbour ) )
                if d is not None:
                    if neighbour not in groups:
                        groups[ neighbour ] = {}
                    if d not in groups[ neighbour ]:
                        groups[ neighbour ][ d ] = []
                    groups[ neighbour ][ d ].append( candidate )
                    if len( groups[ neighbour ][ d ] ) > 5:
                        print( groups[ neighbour ][ d ] )
                        return
            primes.append( candidate )
        candidate += 2

solve()
