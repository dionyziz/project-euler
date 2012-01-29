def f( n ):
    if n == 2:
        return 0
    return fxa( n - 1 ) + fx0( n - 1 ) + fx1( n - 1 ) + 16 * f( n - 1 )
def fxa( n ):
    if n == 0:
        return 1
    return fx0a( n - 1 ) + fx1a( n - 1 ) + 15 * fxa( n - 1 )
def fx0( n ):
    if n == 0:
        return 1
    return fx0a( n - 1 ) + fx01( n - 1 ) + 15 * fx0( n - 1 )
def fx1( n ):
    if n == 0:
        return 1
    return fx1a( n - 1 ) + fx01( n - 1 ) + 15 * fx1( n - 1 )
def fx01( n ):
    if n == 0:
        return 1
    return fx( n - 1 ) + 14 * fx01( n - 1 )
def fx0a( n ):
    if n == 0:
        return 1
    return fx( n - 1 ) + 14 * fx0a( n - 1 )
def fx1a( n ):
    if n == 0:
        return 1
    return fx( n - 1 ) + 14 * fx1a( n - 1 )
def fx( n ):
    if n == 0:
        return 1
    return 13 * fx( n - 1 )

print( fxa( 1 ) )
