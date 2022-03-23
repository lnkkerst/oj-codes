#include <stdio.h>

struct Node {
    int h, ind, used, vis;
} nodes[100010];

struct Edge {
    int to, nex;
} edges[400010];

int cnt, tot, time, maxn, f;
int uni[233];

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

void addedge(int u, int v) {
    edges[++cnt].to = v;
    edges[cnt].nex = nodes[u].h;
    ++nodes[v].ind;
    nodes[u].h = cnt;
    nodes[u].used = 1;
    nodes[v].used = 1;
}

void dfs(int fa) {
    if(nodes[fa].vis) {
        f = 0;
        return ;
    }
    nodes[fa].vis = 1;
    for(int i = nodes[fa].h; i; i = edges[i].nex)
        dfs(edges[i].to); 
}

int main() {
    while(233) {
        int u = read(), v = read();
        if(u == -1) return ;
        if(u == 0) {
            f = 1;
            ++time;
            for(int i = 1; i <= maxn; ++i) {
                if(nodes[i].used && !nodes[i].ind) {
                    dfs(i);
                    break;
                }
            }
            for(int i = 1; i <= maxn; ++i)
                if(nodes[i].ind > 1) f = 0;
            for(int i = 1; i <= maxn; ++i)
                if(nodes[i].used && !nodes[i].vis) f = 0;
            if(f) printf("Case %d is a tree.\n", time);
            else printf("Case %d is not a tree.\n", time);
            memset(nodes, 0, sizeof(nodes));
            memset(edges, 0, sizeof(edges));
            cnt = tot = maxn = 0;
        }
        maxn = maxn > (u > v ? u : v) ? maxn : (u > v ? u : v);
        addedge(u, v);
    }
}