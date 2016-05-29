import math

N = 600851475143

for factor in xrange(2, int(math.sqrt(N) + 1)):
    while N % factor == 0:
        N /= factor
    if N == 1:
        break

print factor
