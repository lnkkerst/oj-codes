m, n = map(int, input().split(' '))
print((m**n - m * (m - 1)**(n - 1)) % 100003)