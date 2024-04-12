import random

N = int(1e3)
S = int(1e3)
P = int(1e3)
T = int(1e5)

print(N, S, P, T)

delta_t = random.randrange(1, 30) / 30

print(delta_t)

for i in range(N):
    RN = 1
    v = random.randrange(1, 100000)
    u = random.randrange(1, 100000)
    a = random.randrange(1, 100000)
    b = random.randrange(1, 100000)
    c = random.randrange(1, 100000)
    d = random.randrange(1, 100000)
    print(RN, v, u, a, b, c, d)

for i in range(P):
    r = random.randrange(100000000, 1000000000)
    print(r)

for i in range(S):
    s = random.randrange(0, N + P)
    t = random.randrange(0, N)
    w = random.randrange(1, 20)
    D = random.randrange(1, 1000)
    print(s, t, w, D)
