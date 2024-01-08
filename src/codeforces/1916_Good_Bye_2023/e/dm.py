import random

t = 1
print(t)


def gen_case():
    n = int(3e5)
    print(n)
    for i in range(2, int(1e5) + 1):
        print(i - 1, end=" ")
    for i in range(int(1e5 + 1), n + 1):
        print(i // 2, end=" ")
    print()
    for i in range(n):
        print(random.randint(1, n), end=" ")


for i in range(t):
    gen_case()
