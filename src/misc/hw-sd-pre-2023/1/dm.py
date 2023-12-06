import random

n = 10
a = list(range(1, n + 1))

random.shuffle(a)

print(n)
print(" ".join([str(x) for x in a]))
