N = 50

seen = [2, 3]
def primes():
    for prime in seen:
        yield prime

    candidate = seen[len(seen) - 1] + 2
    while True:
        is_prime = True
        for witness in seen:
            if candidate % witness == 0:
                is_prime = False
            if witness * witness > candidate:
                break
        if is_prime:
            yield candidate
            seen.append(candidate)
        candidate += 2

def prime_factors(n):
    if n == 1:
        return []

    for p in primes():
        if n % p == 0:
            return [p] + prime_factors(n / p)
        if p * p > n:
            return [n]

square_free = set([1])
pascal = [None, [1]]

for i in range(2, N + 1):
    pascal.append([1])
    for j in range(1, i - 1):
        item = pascal[i - 1][j - 1] + pascal[i - 1][j]
        if not item in square_free:
            prev_factor = 1
            is_square_free = True
            for p in prime_factors(item):
                if p == prev_factor:
                    is_square_free = False
                    break
                prev_factor = p
            if is_square_free:
                square_free.add(item)
        pascal[i].append(item)
    pascal[i].append(1)
    # print(pascal[i])

print(sum(square_free))
