import itertools
from progressbar import ProgressBar, Bar, RotatingMarker, ETA, Percentage

DP = [None, {}]

N = 18 # number of digits in the number
K = 10 # base in which we are working
M = 3 # maximum number of particular digit occurences allowed

t = K * [0]
DP[1][tuple(t)] = 0
t[0] = 1
DP[1][tuple(t)] = 0
t[0] = 0

for k in range(1, K):
    if k > 0:
        t[k - 1] = 0
    t[k] = 1
    DP[1][tuple(t)] = 1

for i in range(2, N + 1):
    print('Evaluating %i-digit numbers.' % i)
    DP.append({})

    widgets = [Percentage(), Bar(marker=RotatingMarker()), ' ', ETA()]
    pbar = ProgressBar(widgets=widgets, maxval=(M + 1)**K).start()

    c = 0
    for t in itertools.product(range(0, M + 1), repeat=K):
        s = 0
        tt = list(t)
        for k in range(0, K):
            if t[k] == 0:
                continue
            tt[k] -= 1
            try:
                s += DP[i - 1][tuple(tt)]
            except:
                pass
            tt[k] += 1
        DP[i][t] = s
        c += 1
        pbar.update(c)
    pbar.finish()

print(sum(DP[N].values()))
