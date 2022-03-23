#include <bits/stdc++.h>
using namespace std;

struct Node {
    int h;
    int du1;
    int du2;
    bool del;
} nodes[500010];

struct Edge {
    int to, nex;
    bool vis;
} edges[500010];

int n, cnt, m;

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
    nodes[u].h = cnt;
    ++nodes[v].du1;
    ++nodes[v].du2;
}

int main() {
    n = read(), m = read();
    for(int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        addedge(u, v);
    }
    set<int , less<int > > heap1;
    set<int , greater<int > > heap2;
    for(int i = 1; i <= n; ++i)
        if(!nodes[i].du1) heap1.insert(i), heap2.insert(i);
    int ans1 = 0;
    int last = 0;
    while(!heap1.empty()) {
        int u = *heap1.begin();
        heap1.erase(heap1.begin());
        nodes[u].del = true;
        if(u > last) ++ans1, last = u;
        for(int i = nodes[u].h; i; i = edges[i].nex) {
            int v = edges[i].to;
            --nodes[v].du1;
            if(!nodes[v].du1 && !nodes[v].del) heap1.insert(v);
        }
    }
    for(int i = 1; i <= n; ++i) nodes[i].del = 0;
    int ans2 = 0;
    last = 0;
    while(!heap2.empty()) {
        int u = *heap2.begin();
        heap2.erase(heap2.begin());
        nodes[u].del = true;
        if(u > last) ++ans2, last = u;
        for(int i = nodes[u].h; i; i = edges[i].nex) {
            int v = edges[i].to;
            --nodes[v].du2;
            if(!nodes[v].du2 && !nodes[v].del) heap2.insert(v);
        }
    }
    printf("%d\n%d\n", ans1, ans2);
    return 0;
}