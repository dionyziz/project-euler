N = 20 # number of digits in number
B = 10 # base
K = 9 # maximum sum of three consecutive digits

DP = [None, {(0, 0): 0}]

for d in range(1, B):
    DP[1][(0, d)] = 1

for i in range(2, N + 1):
    DP.append({})
    for a in range(0, B):
        for b in range(0, B):
            DP[i][(a, b)] = 0
            for d in range(0, B):
                if a + b + d <= 9:
                    try:
                        DP[i][(a, b)] += DP[i - 1][(d, a)]
                    except:
                        pass

print(sum(DP[N].values()))
