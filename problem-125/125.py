from math import *

def palindrome( s ):
    return s[ ::-1 ] == s

seen = {}
N = pow( 10, 8 )
sqrtN = int( sqrt( N ) )
for i in xrange( 1, sqrtN ):
    s = i * i
    for j in xrange( i + 1, sqrtN ):
        s += j * j
        if s > N:
            break
        if palindrome( str( s ) ):
            seen[ s ] = True
print sum( iter( seen ) )
