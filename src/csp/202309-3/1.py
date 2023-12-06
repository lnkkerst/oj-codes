MOD = 10**9 + 7


def qmi(x, k, p=MOD):
    res = 1
    while k:
        if k & 1:
            res = (res * x) % p
        x = (x * x) % p
        k >>= 1
    return res


class Node:
    def __init__(self, pre, sup):
        self.pre = pre
        self.sup = sup

    def __add__(self, b):
        return Node((self.pre + b.pre) % MOD, self.sup)

    def __sub__(self, b):
        return Node((self.pre - b.pre + MOD) % MOD, self.sup)

    def __mul__(self, b):
        return Node((self.pre * b.pre) % MOD, self.sup + b.sup)

    def __neg__(self):
        return Node((-self.pre + MOD) % MOD, self.sup)

    def com(self, b):
        return self.sup == b.sup

    def calc(self, x):
        return (self.pre * qmi(x, self.sup)) % MOD


class Nodes:
    def __init__(self, data):
        self.data = data

    def __getitem__(self, index):
        return self.data[index]

    def __add__(self, b):
        res = self.data.copy()
        res.extend(b.data)
        return Nodes(res)

    def __sub__(self, b):
        res = self.data.copy()
        for i in b.data:
            i.pre = (i.pre * -1 + MOD) % MOD
            res.append(i)
        return Nodes(res)

    def __mul__(self, b):
        res = []
        for i in self.data:
            for j in b.data:
                res.append(i * j)
        return Nodes(res)

    def simplify(self):
        res = []
        b = {}
        for i in self.data:
            if i.sup in b:
                b[i.sup].append(i)
            else:
                b[i.sup] = [i]
        for i in b.values():
            tmp = i[0]
            for j in range(1, len(i)):
                tmp = tmp + i[j]
            res.append(tmp)
        return Nodes(res)

    def calc(self, x):
        res = 0
        for i in self.data:
            res += i.calc(x)
            res %= MOD
        return res


def solve():
    n, m = map(int, input().split())
    s = input().strip()
    b = s.split()
    for _ in range(m):
        inp = list(map(int, input().split()))
        id_val = inp[0]
        a = [0] + inp[1:]
        st = []
        for s in b:
            if s[0] == "x":
                cid = int(s[1:])
                if cid != id_val:
                    st.append(Nodes([Node(a[cid], 0)]))
                else:
                    st.append(Nodes([Node(1, 1)]))
            elif s in ["*", "+", "-"]:
                t1 = st.pop()
                t2 = st.pop()
                if s == "*":
                    st.append((t1 * t2).simplify())
                elif s == "+":
                    st.append((t1 + t2).simplify())
                else:
                    st.append((t2 - t1).simplify())
            else:
                st.append(Nodes([Node(int(s), 0)]))

        fx = st[-1].simplify()
        for x in fx.data:
            if x.sup == 0:
                x.pre = 0
            else:
                x.pre = x.sup * x.pre % MOD
                x.sup = (x.sup - 1 + MOD) % MOD

        result = (fx.calc(a[id_val]) % MOD + MOD) % MOD
        print(result)


t = 1
while t > 0:
    solve()
    t -= 1
