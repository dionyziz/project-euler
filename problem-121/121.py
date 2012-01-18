from math import *
from fractions import *
from functools import *

def prob( d ):
    return Fraction( 1, 1 + d )

N = 15
t = 0
for i in range( 0, int( pow( 2, N ) ) ):
    if bin( i ).count( '1' ) > floor( N / 2 ):
        n = list( zip( bin( i )[ 2: ].zfill( N ), range( 1, N + 1 ) ) )
        loses = [ 1 - prob( d ) for ( i, d ) in n if i == '0' ]
        wins = [ prob( d ) for ( i, d ) in n if i == '1' ]
        t += reduce( lambda x, y: x * y, wins + loses, 1 )
print( t )
