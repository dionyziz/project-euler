DP = [[1, 0]]
N = 50
for i in range(1, N + 1):
    DP.append([DP[i - 1][0] + DP[i - 1][1], 0])
    for j in range(3, i + 1):
        DP[i][1] += DP[i - j][0]
print(DP[N][0] + DP[N][1])
