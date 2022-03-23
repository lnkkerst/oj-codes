#include <stdio.h>

int fa[233333], used[233333];
int u, v, maxn = -1, tot;

int read() {
    int ret, f = 1;
    char ch;
    while(!isdigit(ch = getchar())) (ch == '-') && (f = -1);
    for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
    return ret * f;
}
void print(int x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    while(233) {
        u = read(), v = read();
        if(u == -1 && v == -1) return 0;
        if(!u && !v) {
            int f = 1;
            for(int i = 1; i <= maxn; ++i)
                if(used[i] && fa[i] > 1) {
                    printf("Case %d is not a tree.\n", ++tot);
                    f = 0;
                }
            if(f) printf("Case %d is a tree.\n", ++tot);
            memset(fa, 0, sizeof(fa));
            memset(used, 0, sizeof(used));
        }
        ++fa[v];
        used[v] = used[u] = 1;
        maxn = maxn > (v > u ? v : u) ? maxn : (v > u ? v : u);
    }
}