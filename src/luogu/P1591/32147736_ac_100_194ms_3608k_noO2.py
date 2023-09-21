t = int(input())
for k in range(t):
    inp = input().split()
    n = int(inp[0])
    a = int(inp[1])
    res = 1
    for i in range(1, n + 1):
        res *= i
    res = str(res)
    ans = 0
    for i in res:
        if int(i) == a:
            ans += 1
    print(ans)
