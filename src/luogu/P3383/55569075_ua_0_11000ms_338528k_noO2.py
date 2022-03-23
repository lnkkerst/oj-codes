b = {}
a = []
cnt = 0;
n, q = [int(x) for x in input().split(' ')]
for i in range(2, n + 1):
    if not i in b:
        a.append(i)
    j = 1
    while j <= len(a) and i * a[j - 1] <= n:
        b[a[j - 1] * i] = 1
        if not i % a[j - 1]:
            break;
        j = j + 1
for i in range(q):
    print(a[int(input()) - 1])
# print(a)