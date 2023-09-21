n = int(input())
ans = 0
t = 1
for i in range(1, n + 1):
    t *= i
    ans += t
print(ans)
