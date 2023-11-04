import random

t = 10


def gen_case():
    n = 2
    m = 1000
    print(n, m)
    for _ in range(n):
        print(random.randrange(1, n + 1), end=" ")


print(t)
for _ in range(t):
    gen_case()
