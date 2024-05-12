import random

n = 10
m = 10
sx = 0
sy = 0

print(n, m, sx, sy)

op = "LRUD"
s = "".join([op[random.randrange(0, 4)] for _ in range(n)])
print(s)

for i in range(m):
    x = random.randint(-10, 10)
    y = random.randint(-10, 10)
    if x == 0 and y == 0:
        x = x + 1
    print(x, y)
