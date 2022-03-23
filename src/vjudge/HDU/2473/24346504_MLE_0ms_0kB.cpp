#include <cstdio>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <cstring>

int fa[1500010], cnt, n, m;
bool b[1500010];

int read() {
    int ret, fl = 1;
    char ch;
    while(!isdigit(ch = getchar())) (ch == '-') && (fl = -1);
    for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
    return ret * fl;
}

void init(int tot) {
    memset(fa, 0, sizeof(fa));
    memset(b, 0, sizeof(b));
    cnt = 0;
    for(int i = 0; i < tot; ++i) fa[i] = i;
}

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    fa[find(x)] = find(y);
}

void print(int x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

void sepa(int x) {
    fa[x] = ++cnt + n - 1;
}

int main() {
    while(233) {
        n = read(), m = read();
        if(!n && !m) return 0;
        init(n);
        for(int i = 1; i <= m; ++i) {
            char opt = getchar();
            while(opt != 'M' && opt != 'S')
                opt = getchar();
            if(opt == 'M') merge(read(), read());
            else sepa(read());
        }
        int ans = 0;
        for(int i = 0; i < cnt + n; ++i)
            if(!b[fa[i]]) ++ans, b[fa[i]] = 1;
        print(ans), putchar('\n');
    }
    return 0;
}