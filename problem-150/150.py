from progressbar import ProgressBar, Bar, RotatingMarker, ETA, Percentage

def by_location(row, column):
    return row * (row - 1) / 2 + column

def left_child(row, column):
    return by_location(row + 1, column) 

def right_child(row, column):
    return by_location(row + 1, column + 1) 

def grand_child(row, column):
    return by_location(row + 2, column + 1)

s = [None]
DP = [None]
m = 0

t = 0
N = 1000
K = N * (N + 1) / 2
for k in range(1, K + 1):
    t = (615949 * t + 797807) % 2**20
    item = t - 2**19
    s.append(item)
    DP.append([None, item])

# s = [None, 15, -14, -7, 20, -13, -5, -3, 8, 23, -26, 1, -4, -5, -18, 5, -16, 31, 2, 9, 28, 3]
# DP = []
# for i in s:
#     DP.append([None, i])

widgets = [Percentage(), Bar(marker=RotatingMarker()), ' ', ETA()]
pbar = ProgressBar(widgets=widgets, maxval=N).start()

for row in range(N, 0, -1):
    for column in range(1, row + 1):
        i = by_location(row, column)
        for size in range(2, N - row + 2):
            item = s[i] + \
                   DP[left_child(row, column)][size - 1] + \
                   DP[right_child(row, column)][size - 1]
            if size >= 3:
                item -= DP[grand_child(row, column)][size - 2]

            DP[i].append(item)
            m = min(m, DP[i][size])
    pbar.update(N - row)
pbar.finish()

print(m)
