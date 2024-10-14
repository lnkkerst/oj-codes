import random

n = 4
print(n)

mp = {}

for i in range(n):
    x = random.randrange(0, 5)
    y = random.randrange(0, 5)
    while f"{x}:{y}" in mp:
        x = random.randrange(0, 5)
        y = random.randrange(0, 5)
    mp[f"{x}:{y}"] = 1

    print(x, y)
