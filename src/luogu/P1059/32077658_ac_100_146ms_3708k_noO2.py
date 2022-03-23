input()
a = input().split()
b = set()
for i in a:
    b.add(int(i))
print(len(b))
for i in sorted(b):
    print(i, end = ' ')