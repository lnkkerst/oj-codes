import copy
import functools

(n, m) = [int(x) for x in input().strip().split()]

kyq = [{"jsjd": [], "jsjdd": {}, "id": x + 1} for x in range(m)]
jsjd = [{"kyq": 0, "id": x + 1, "jsrwcnt": 0, "yyd": {}} for x in range(n)]
yy = {}

for i, j in enumerate([int(x) for x in input().strip().split()]):
    kyq[j - 1]["jsjd"].append(i + 1)
    kyq[j - 1]["jsjdd"][i + 1] = True
    jsjd[i]["kyq"] = j

g = int(input().strip())


def check_yy(app_id):
    global yy
    if not app_id in yy:
        yy[app_id] = {"kyq": [], "kyqd": {}}


def cmp(a, b):
    if a["jsrwcnt"] > b["jsrwcnt"]:
        return 1
    if a["jsrwcnt"] < b["jsrwcnt"]:
        return -1
    if a["id"] > b["id"]:
        return 1
    if a["id"] < b["id"]:
        return -1
    return 0


def solve_one(a, na, pa, paa, paar):
    n_jsjd = copy.copy(jsjd)
    if na != 0:
        n_jsjd = filter(lambda x: x["kyq"] == na, n_jsjd)
    if pa != 0:
        check_yy(pa)
        n_jsjd = filter(lambda x: x["kyq"] in yy[pa]["kyqd"], n_jsjd)
    n_jsjd = list(n_jsjd)
    n_jsjdr = copy.copy(n_jsjd)
    if paa != 0:
        n_jsjdr = list(filter(lambda x: not paa in x["yyd"], n_jsjdr))
    ans_jsjd = n_jsjdr
    if len(ans_jsjd) == 0 and paar == 0:
        ans_jsjd = n_jsjd
    if len(ans_jsjd) == 0:
        print("0 ", end="")
        return
    ans_jsjd.sort(key=functools.cmp_to_key(cmp))
    ans = ans_jsjd[0]
    if not a in yy:
        yy[a] = {"kyq": [], "kyqd": {}}
    yy[a]["kyq"].append(ans["kyq"])
    yy[a]["kyqd"][ans["kyq"]] = True
    jsjd[ans["id"] - 1]["jsrwcnt"] += 1
    jsjd[ans["id"] - 1]["yyd"][a] = True
    print(ans["id"], end=" ")


for i in range(g):
    f, a, na, pa, paa, paar = [int(x) for x in input().strip().split()]
    for j in range(f):
        solve_one(a, na, pa, paa, paar)
    print()
