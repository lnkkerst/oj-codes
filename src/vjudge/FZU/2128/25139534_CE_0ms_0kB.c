#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int l, r;
} Node;

Node q[1000010];
int kmp[233], n, cnt = 0;
char a[100010], b[233];

int mstrlen(char s[]) {
    int ret = -1;
    while(s[++ret]);
    return ret;
}

void ckmp() {
    kmp[0] = kmp[1] = kmp[2] = 0;
    int la = mstrlen(a + 1), lb = mstrlen(b + 1), j = 0;
    for(int i = 2; i <= lb; ++i) {
        while(j && b[i] != b[j + 1]) j = kmp[j];
        if(b[j + 1] == b[i]) ++j;
        kmp[i] = j;
    } j = 0;
    for(int i = 1; i <= la; ++i) {
        while(j > 0 && b[j + 1] != a[i]) j = kmp[j];
        if(b[j + 1] == a[i]) ++j;
        if(j == lb) {
            q[++cnt] = (Node){i - lb + 1, i};
            j = kmp[j];
        }
    }
}

int cmp(const void *x, const void *y) {
    if(((Node*)x)->l == ((Node*)y)->l)
        return ((Node*)x)->r - ((Node*)y)->r;
    return ((Node*)x)->l - ((Node*)y)->l;
}

int max(int x, int y) {
    return x > y ? x : y;
}

int main() {
    while(~scanf("%s%d", a + 1, &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%s", b + 1);
            ckmp();
        }
        qsort(q + 1, cnt, sizeof(Node), cmp);
        int ans = -1;
        for(int i = 2; i <= cnt; ++i)
            ans = max(ans, q[i].r - q[i - 1].l - 1);
        if(ans == -1) printf("%d\n", mstrlen(a + 1));
        else printf("%d\n", ans);
        cnt = 0;
    }
    return 0;
}