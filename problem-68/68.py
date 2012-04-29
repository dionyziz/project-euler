from itertools import permutations

M = 0
for r in permutations( range( 1, 11 ) ):
    s = r[ 0 ] + r[ 1 ] + r[ 2 ]
    if r[ 0 ] > r[ 3 ] or r[ 0 ] > r[ 5 ] 
    or r[ 0 ] > r[ 7 ] or r[ 0 ] > r[ 9 ] \
    or r[ 3 ] + r[ 2 ] + r[ 4 ] != s \
    or r[ 5 ] + r[ 4 ] + r[ 6 ] != s \
    or r[ 7 ] + r[ 6 ] + r[ 8 ] != s \
    or r[ 9 ] + r[ 8 ] + r[ 1 ] != s:
        continue
    m = "".join( map( 
        lambda x: str( x ), [
            r[ 0 ], r[ 1 ], r[ 2 ],
            r[ 3 ], r[ 2 ], r[ 4 ],
            r[ 5 ], r[ 4 ], r[ 6 ],
            r[ 7 ], r[ 6 ], r[ 8 ],
            r[ 9 ], r[ 8 ], r[ 1 ]
        ]
    ) )
    M = max( M, m )
print( M )
