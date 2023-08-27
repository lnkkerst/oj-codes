import random

n = 500000

print(1)
print(n)

for i in range(n):
    print(random.randrange(1, int(1e9) // 2) * 2 + 1)
