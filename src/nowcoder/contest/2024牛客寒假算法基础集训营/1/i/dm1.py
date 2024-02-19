import random

n = int(1e5)
print(n)

for i in range(n):
    x = random.randrange(-99, 99)
    y = random.randrange(-99, 99)
    while True:
        r = random.randrange(1, 100)
        if x + r <= 100 and x - r >= -100 and y + r <= 100 and y - r >= -100:
            print(x, y, r)
            break
