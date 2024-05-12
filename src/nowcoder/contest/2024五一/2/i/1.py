t = int(input().strip())

for _ in range(0, t):
    n = int(input().strip())
    a = input().strip().split()
    a = "".join(sorted(a))
    c = a.count("0")
    a = a[c:]
    print(int(a[:1]) * int(a[1] + ("0" * c) + a[2:]))
