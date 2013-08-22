N = 40
B = 10
DP = [None, []]

for m in range(0, 1 << B):
    DP[1].append([])
    for d in range(0, B):
        if d != 0 and m == 1 << d:
            DP[1][m].append(1)
        else:
            DP[1][m].append(0)

S = 0
for i in range(2, N + 1):
    DP.append([])
    for m in range(0, 1 << B):
        DP[i].append([])
        for d in range(0, B):
            if m & (1 << d) != 0:
                item = 0
                if d > 0:
                    item += DP[i - 1][m][d - 1]
                    item += DP[i - 1][m & ~(1 << d)][d - 1]
                if d < B - 1:
                    item += DP[i - 1][m][d + 1]
                    item += DP[i - 1][m & ~(1 << d)][d + 1]
                DP[i][m].append(item)
            else:
                DP[i][m].append(0)
            if m == (1 << B) - 1:
                S += DP[i][m][d]

print(S)
