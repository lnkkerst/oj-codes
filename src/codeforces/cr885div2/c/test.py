def calc(x: int, y: int):
    res = 0
    while x != 0:
        x, y = y, abs(x - y)
        res = res + 1
    return res


# y = 10
# for x in range(64, 100, y):
#     print(x, calc(x, y))
#
# exit(0)

while True:
    x, y = map(int, input().strip().split())
    print(calc(x, y))
