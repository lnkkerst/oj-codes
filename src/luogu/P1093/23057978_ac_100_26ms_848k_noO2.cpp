#include <cstdio>
#include <algorithm>

using namespace std;

struct mem {
    int no, ch, ma, en, tot;
} stu[400];

bool cmp(mem a, mem b) {
    return a.tot == b.tot ? a.ch == b.ch ? a.no < b.no : a.ch > b.ch : a.tot > b.tot;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d%d%d", &stu[i].ch, &stu[i].ma, &stu[i].en);
        stu[i].no = i;
        stu[i].tot = stu[i].ch + stu[i].ma + stu[i].en;
    }

    sort(stu + 1, stu + n + 1, cmp);

    for(int i = 1; i <= 5; ++i)
        printf("%d %d\n", stu[i].no, stu[i].tot);

    return 0;
}