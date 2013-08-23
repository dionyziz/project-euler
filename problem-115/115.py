from itertools import count

DP = [[1, 0]]
M = 50
for i in count(1):
    DP.append([DP[i - 1][0] + DP[i - 1][1], 0])
    for j in range(M, i + 1):
        DP[i][1] += DP[i - j][0]
    if DP[i][0] + DP[i][1] > 1000000:
        print(i)
        break
