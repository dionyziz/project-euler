import math

N = 2000000
primes = [2]

candidate = 3
while candidate < N:
    prime = True
    for witness in range(2, int(math.sqrt(candidate) + 2)):
        if candidate % witness == 0:
            prime = False
            break
    if prime:
        primes.append(candidate)
    candidate += 2

print sum(primes)
