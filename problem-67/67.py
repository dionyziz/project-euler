DP = []
with open('67.in') as f:
    for i, line in enumerate(f.readlines()):
        DP.append(map(int, line.split(' ')))
        if i > 0:
            for j, item in enumerate(DP[i]):
                if j == 0:
                    DP[i][j] = DP[i - 1][j] + DP[i][j]
                elif j == i:
                    DP[i][j] = DP[i - 1][j - 1] + DP[i][j]
                else:
                    DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]) + DP[i][j]
    print(max(DP[-1]))
