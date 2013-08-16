DP = [0, 0, 0, 1]
N = 50
for i in range(1 + 3, N + 1 + 3):
    DP.append(DP[i - 1] + DP[i - 2] + DP[i - 3] + DP[i - 4])
print(DP[N + 3])
