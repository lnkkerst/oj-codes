import random


def get_e(n):
    return list(range(1, n + 1))


n = 10
m = 18

print(n, m)
for i in range(m):
    a = get_e(n)
    random.shuffle(a)
    print(" ".join([str(i) for i in a]))
