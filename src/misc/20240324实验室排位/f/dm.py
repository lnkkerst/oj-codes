import random

t = 10


def gen_case():
    n = int(1e5)
    m = n
    print(n, m)
    for i in range(1, n + 1):
        print(i, i % n + 1)


print(t)
for _ in range(t):
    gen_case()
