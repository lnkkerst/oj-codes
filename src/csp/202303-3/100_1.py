s = ""
sx = {}
ns = []


def isdigit(s):
    if ord(s) >= ord("0") and ord(s) <= ord("9"):
        return True
    else:
        return False


def split_num(i: int, l: int, r: int, after: bool = False):
    res = 0
    if not after:
        while i >= l and isdigit(s[i]):
            res = res * 10 + int(s[i])
            i = i - 1
    else:
        while i <= r and isdigit(s[i]):
            res = res * 10 + int(s[i])
            i = i + 1
    return res


def find_right(l: int):
    r = l + 1
    cnt = 1
    while True:
        if s[r] == "(":
            cnt = cnt + 1
        if s[r] == ")":
            cnt = cnt - 1
        if cnt == 0:
            break
        r = r + 1
    return r


def build_tree(l, r):
    if s[l] == "(":
        l = l + 1
        r = r - 1
    if s[l] == "|" or s[l] == "&":
        ll = l + 1
        lr = find_right(ll)
        rl = lr + 1
        rr = find_right(rl)
        t = {}
        t["type"] = 0
        if s[l] == "&":
            t["oper"] = 0
        else:
            t["oper"] = 1
        t["ls"] = build_tree(ll, lr)
        t["rs"] = build_tree(rl, rr)
        ns.append(t)
        return len(ns) - 1
    t = {}
    t["type"] = 1
    ln = split_num(l, l, r, True)
    rn = split_num(l + len(str(ln)) + 1, l, r, True)
    if (s[l + len(str(ln))]) == ":":
        t["oper"] = 0
    else:
        t["oper"] = 1
    t["op"] = [ln, rn]
    ns.append(t)
    return len(ns) - 1


def dfs(u: int):
    if ns[u]["type"] == 0:
        if ns[u]["oper"] == 0:
            return dfs(ns[u]["ls"]) and dfs(ns[u]["rs"])
        else:
            return dfs(ns[u]["ls"]) or dfs(ns[u]["rs"])

    if ns[u]["oper"] == 0:
        return ns[u]["op"][0] in sx and sx[ns[u]["op"][0]] == ns[u]["op"][1]
    return ns[u]["op"][0] in sx and sx[ns[u]["op"][0]] != ns[u]["op"][1]


n = int(input().strip())
user = []
for i in range(n):
    ip = [int(x.strip()) for x in input().split()]
    dn = ip[0]
    sx_cnt = ip[1]
    sx = {}
    for j in range(2, len(ip), 2):
        sx[ip[j]] = ip[j + 1]
    user.append({"dn": dn, "sx_cnt": sx_cnt, "sx": sx})

m = int(input().strip())
for t in range(m):
    s = input().strip()
    rt = build_tree(0, len(s) - 1)

    def filter_f(val):
        global sx
        sx = val["sx"]
        a = dfs(rt)
        return a

    ans_user = list(filter(filter_f, user))
    ans_op = [x["dn"] for x in ans_user]
    ans_op.sort()
    for i in ans_op:
        print(i, end=" ")
    print("")
