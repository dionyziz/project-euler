def s( p1, p2 ):
    i = 0
    sp1 = str( p1 )
    while True:
        candidate = str( i ) + sp1
        if int( candidate ) % p2 == 0:
            return int( candidate )
        i += 1

N = 1000000
sigma = 0

primes = [ 2, 3, 5 ]
prev = 5
candidate = 7

while True:
    prime = True
    for witness in primes:
        if candidate % witness == 0:
            prime = False
    if prime:
        primes.append( candidate )
        sigma += s( prev, candidate )
        prev = candidate
        if prev > N:
            break
    candidate += 2
    if candidate % 1000 == 1:
        print "%i%%" % ( ( 100 * candidate ) / N )

print sigma
