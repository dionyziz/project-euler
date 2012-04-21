def isPrime( n ):
    if n == 2 or n == 3:
        return True
    if n % 2 == 0:
        return False
    d = n - 1
    s = 0
    while d % 2 == 0:
        d = d / 2
        s = s + 1
    for a in [ 2, 7, 61 ]:
        x = pow( a, d, n )
        if x == 1 or x == n - 1:
            continue
        prime = False
        for r in range( 1, s ):
            x = ( x * x ) % n
            if x == 1:
                return False
            if x == n - 1:
                prime = True
                break
        if not prime:
            return False
    return True
