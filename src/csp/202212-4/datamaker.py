import random

n = 300000
# a = list(range(n + 1))[2:]
a = [random.randrange(1, n) for _ in range(n - 1)]
random.shuffle(a)
a = [x // 2 for x in range(2, n + 1)]
b = list(range(n + 1))[1:]
b = [random.randrange(1, n) for _ in range(n)]
random.shuffle(b)
print(n)
print(" ".join([str(x) for x in a]))
print(" ".join([str(x) for x in b]))
