N = 100

DP = [[], [0]]
for k in range(1, 10):
    DP[1].append(1)
for n in range(2, N + 1):
    DP.append([0])
    for k in range(1, 10):
        DP[n].append(0)
        for l in range(1, k + 1):
            DP[n][k] += DP[n - 1][l]

DPp = [[], [0]]
for k in range(1, 10):
    DPp[1].append(1)
for n in range(2, N + 1):
    DPp.append([0])
    for k in range(0, 10):
        DPp[n].append(0)
        for l in range(k, 10):
            DPp[n][k] += DPp[n - 1][l]

S = 0
for n in range(1, N + 1):
    for d in range(0, 10):
        S += DP[n][d] + DPp[n][d]
    S -= 9
print("%i" % S)
