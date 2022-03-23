input()
a = input().split()
b = set()
for i in a:
    b.add(int(i))
print(len(b))
for i in b:
    print(i, end = ' ')