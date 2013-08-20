import itertools

DP = [None, {(0): 1, (1): 1, (2): 1}]

N = 8

def flip(a):
    number = []
    for i in a:
        digit = [d for d in (0, 1, 2) if d != i]
        number.append(digit)
    return itertools.product(*number)

def double_flip(a):
    number = [[d for d in (0, 1, 2) if d != a[0]]]
    for i in range(0, len(a) - 1):
        number.append([d for d in (0, 1, 2) if d != a[i] and d != a[i + 1]])
    number.append([d for d in (0, 1, 2) if d != a[len(a) - 1]])
    return itertools.product(*number)

for i in range(2, N + 1):
    DP.append({})
    for a, v in DP[i - 1].iteritems():
        if isinstance(a, tuple):
            la = list(a)
        else:
            la = [a]
        for a_prime in flip(la):
            for b in double_flip(a_prime):
                bt = tuple(b)
                if bt not in DP[i]:
                    DP[i][bt] = 0
                DP[i][bt] += v

c = 0
for b, v in DP[N].iteritems():
    c += v

print(c)
