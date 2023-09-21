def pd(x):
    if x == 1:
        return False
    if x == 2 or x == 3:
        return True
    if x % 6 != 1 and x % 6 != 5:
        return False
    i = 5
    while i * i <= x:
        if not x % i or not x % (i + 2):
            return False
        i = i + 6
    return True


n = int(input())
for i in map(int, input().split(" ")):
    if pd(i):
        print(i, end=" ")
