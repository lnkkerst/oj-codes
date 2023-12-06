def gen_case():
    n = int(1e4)
    q = int(1e4)
    print(n, q)
    for i in range(2, n + 1):
        print(i, i - 1)
    print(" ".join(str(i) for i in range(1, n + 1)))
    for i in range(q):
        print(1, n, i + 1)


t = 1
print(t)
for i in range(t):
    gen_case()
