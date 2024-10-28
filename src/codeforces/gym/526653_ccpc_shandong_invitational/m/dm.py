import random


t = 1

print(t)


def gen_case():
    n = 4
    print(n)
    print(" ".join([str(random.randrange(1, 3)) for _ in range(n)]))
    for i in range(n):
        print(i * i, i * i * 2)


for _ in range(t):
    gen_case()
