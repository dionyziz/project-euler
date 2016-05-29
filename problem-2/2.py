from itertools import takewhile

N = 4000000

def fib():
    a, b = 0, 1
    while True:
        a, b = b, a + b
        yield b

seq = fib()
seq = takewhile(lambda x: x <= N, seq)
seq = filter(lambda x: x % 2 == 0, seq)

print sum(seq)
