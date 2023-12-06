import random


def gen_case():
    n = int(1e3)
    print(n)
    a = []
    for i in range(n):
        a.append(random.randint(1, int(1e9)))
    print(" ".join(map(str, a)))


t = 1
print(t)
for i in range(t):
    gen_case()
