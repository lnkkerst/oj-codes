b = {}
a = []
cnt = 0;
n, q = [int(x) for x in input().split(' ')]
for i in range(2, n + 1):
    if not i in b:
        a.append(i)
        for j in range(i, (n // i) + 1):
            b[i * j] = 1
for i in range(q):
    print(a[int(input()) - 1])
# print(a)