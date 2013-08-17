c = 0
N = 6

for i in range(1, 10 ** N):
    i_str = str(i)
    is_increasing = True
    is_decreasing = True
    for j in range(0, len(i_str) - 1):
        if i_str[j] > i_str[j + 1]:
            is_increasing = False
        if i_str[j] < i_str[j + 1]:
            is_decreasing = False
    if is_increasing or is_decreasing:
        c += 1
print(c)
