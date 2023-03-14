import random

n = 1000
m = 1000

print(n, m)

for i in range(n):
    print(random.randrange(0, m), end=" ")

print()

g = 2000

print(g)

for i in range(g):
    a = random.randrange(0, 1000000000000000000)
    na = random.randrange(0, m)
    pa = random.randrange(0, 100000000000000000)
    paa = random.randrange(0, 100000000000000)
    paar = random.randrange(0, 1000) % 2
    print(1, a, na, pa, paa, paar)
