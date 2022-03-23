n = int(input())
ma = 0
ans = 0
# a = map(int, input().split(' '))
a = []
for i in range(n):
    a.append(int(input()))
b = [0 for x in range(5010)]
for i in a:
    b[i] = b[i] + 1
    ma = max(ma, i)
i = ma
while i >= 1:
    if b[i] < 2:
        i = i - 1
        continue
    j = i - 1
    while j >= ((i + 1) // 2):
        if j != i - j:
            ans = ans + ((b[i] * (b[i] - 1)) // 2) * b[j] * b[i - j]
        elif b[j] >= 2:
            ans = ans + ((b[i] * (b[i] - 1)) // 2) * ((b[j] * (b[j] - 1)) // 2)
        j = j - 1
    i = i - 1
print(ans)