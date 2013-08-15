from itertools import count
import sys

BOUND = 10 ** 10
primes = [2]
candidate = 3
for n in count(2):
    prime_found = False
    while not prime_found:
        prime_found = True
        for witness in primes:
            if candidate % witness == 0:
                prime_found = False
                break
        if prime_found:
            primes.append(candidate)
            mod = candidate ** 2
            a = pow(candidate - 1, n, mod)
            b = pow(candidate + 1, n, mod)
            if (a + b) % mod > BOUND:
                print(n)
                sys.exit(0)
        candidate += 2
