import random

t = 1
print(t)


def gen_case():
    n = int(2e5)
    k = int(1e6)
    print(n, k)
    for i in range(n - 1):
        print(int(1e12), end=" ")
        continue
        print(random.randint(1, int(1e12)), end=" ")
    print(int(1e12) - 1)


gen_case()
