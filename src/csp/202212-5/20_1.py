MOD = 10**9 + 7

MAX = 2**1000 * 10**10


def solve():
    n, m = map(int, input().split())
    e = [[MAX] * (n + 1) for _ in range(n + 1)]
    for _ in range(m):
        l1, r1, l2, r2, a, b = map(int, input().split())
        w = a << b
        for i in range(l1, r1 + 1):
            for j in range(l2, r2 + 1):
                e[i][j] = min(e[i][j], w)

    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                e[i][j] = min(e[i][j], e[i][k] + e[k][j])

    for i in range(2, n + 1):
        if e[1][i] == MAX or e[i][1] == MAX:
            print(-1, end=" ")
        else:
            print((e[1][i] % MOD + e[i][1] % MOD) % MOD, end=" ")
    print()


def main():
    t = 1
    while t > 0:
        solve()
        t -= 1


if __name__ == "__main__":
    main()
