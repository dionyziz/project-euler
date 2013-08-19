from millerrabin import is_prime

def non_increasing_sequence(length, maximum):
    ret = length * [0]
    yield ret

    found = True
    while found:
        found = False
        for i in range(0, length):
            ret[i] += 1
            if ret[i] > maximum:
                ret[i] = 0
            else:
                found = True
                for j in range(0, i):
                    ret[j] = ret[i]
                break
        if found:
            yield ret

def intermediate_combine(M, d, counter_str):
    d_str = str(d)
    for seq in non_increasing_sequence(M, len(counter_str)):
        seqq = list(seq)
        ret = ''
        for i in range(0, len(counter_str)):
            while len(seqq) != 0 and seqq[len(seqq) - 1] == i:
                ret += d_str
                seqq.pop()
            ret += counter_str[i]
        while len(seqq):
            ret += d_str
            seqq.pop()
        yield int(ret)

S = 0
n = 10

for d in range(0, 10):
    prime_found = False
    N = 0
    for M in range(n, 0, -1):
        for counter in range(0, 10 ** (n - M)):
            counter_str = str(counter)
            counter_str = ((n - M) - len(counter_str)) * '0' + counter_str

            for candidate in intermediate_combine(M, d, counter_str):
                 if len(str(candidate)) == n and is_prime(candidate):
                     prime_found = True
                     S += candidate
                     N += 1
        if prime_found:
            break
print(S)
