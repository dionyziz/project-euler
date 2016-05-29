import math

primes = [2]

candidate = 3
while len(primes) < 10001:
    prime = True
    for witness in range(2, int(math.sqrt(candidate) + 2)):
        if candidate % witness == 0:
            prime = False
            break
    if prime:
        primes.append(candidate)
    candidate += 2

print primes[-1]
