# naive solution, for verification

import math

def f(i):
    ret = 0
    for d in str(i):
        ret += int(d)**2
    return ret

s = 0
N = 2
for i in range(1, 10**N):
    j = f(i)
    if math.floor(math.sqrt(j))**2 == j:
        s += i

print(s)
