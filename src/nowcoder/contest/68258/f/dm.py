t = 1


def gen_case():
    n = 50
    m = 5
    print(n, m)
    s = "a" * n
    t = "a" * m
    print(s, t, sep="\n")


print(t)

for i in range(t):
    gen_case()
