import random

t = 1


def gen_case():
    n = int(1e4)
    print(n)
    for i in range(n):
        print(random.randint(1, int(1e5)), end=" ")


print(t)
for i in range(t):
    gen_case()
