from math import *

def palindrome( s ):
    return str( s )[ ::-1 ] == str( s )

seen = {}
ret = 0
N = pow( 10, 8 )
sqrtN = int( sqrt( N ) )
for i in xrange( 1, sqrtN ):
    s = i * i
    for j in xrange( i + 1, sqrtN ):
        s = s + j * j
        if s > N:
            break
        if palindrome( s ) and s not in seen:
            seen[ s ] = True
            ret = ret + s
print ret
