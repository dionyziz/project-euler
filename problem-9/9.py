import math

pythagoras = []

for c in range(1, 1000):
    for b in range(1, c):
        a = math.sqrt(c * c - b * b)
        if a == float(int(a)):
            pythagoras.append((int(a), b, c))

products = {a + b + c: a * b * c for a, b, c in pythagoras}

print products[1000]
