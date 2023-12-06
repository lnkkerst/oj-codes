import re

t = int(input().strip())

for _ in range(t):
    n = int(input().strip())
    s = input().strip()
    a = re.split(r"#+", s)
    if len(a) == 0:
        print(0)
        continue
    su = 0
    fl = True
    for i in [len(x) for x in a]:
        if i >= 3:
            print(2)
            fl = False
            break
        su = su + i

    if fl:
        print(su)
