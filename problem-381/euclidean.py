def inverse( a, p ):
    return extended( a, p )[ 0 ] % p

def extended( a, b ):
    if b == 0:
        return ( 1, 0 )
    ( s, t ) = extended( b, a % b )
    return ( t, s - ( a / b ) * t )
