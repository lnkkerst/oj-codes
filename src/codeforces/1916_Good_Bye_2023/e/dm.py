import random

t = 1
print(t)


def gen_case():
    n = int(2e4)
    print(n)
    for i in range(2, n // 2):
        print(i - 1, end=" ")
    for i in range(n // 2, n + 1):
        print(i // 2, end=" ")
    print()
    for i in range(n):
        print(random.randint(1, n), end=" ")


for i in range(t):
    gen_case()
