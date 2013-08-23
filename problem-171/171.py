import math

DP = [None, {}]

B = 10 # base
N = 20  # number of digits in number
MOD = 10**9

s = 0
for d in range(1, B):
    DP[1][d * d] = {'sum': d, 'count': 1}
    s += d

for i in range(2, N + 1):
    DP.append({})
    for f, v in DP[i - 1].items():
        for d in range(0, B):
            f_p = f + d * d
            if f_p not in DP[i]:
                DP[i][f_p] = {'sum': 0, 'count': 0}
            DP[i][f_p]['count'] += DP[i - 1][f]['count']
            DP[i][f_p]['sum'] += 10 * DP[i - 1][f]['sum'] + d * DP[i - 1][f]['count']
    for f, v in DP[i].items():
        if math.floor(math.sqrt(f)) ** 2 == f:
            s += v['sum']
            s %= MOD

print(s)
