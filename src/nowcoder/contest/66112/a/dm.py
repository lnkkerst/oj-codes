import random

n = 3000
k = int(1e9)
print(n, k)
for i in range(n):
    print(chr(random.randrange(ord("a"), ord("z"))), end="")
