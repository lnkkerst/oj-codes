#include <cstdio>
#include <bits/stdc++.h>

struct Edge {
    int v, w, nex;
} edges[10086];

struct Heap {
    struct Mem {
        int f, s;
    } mem[400086];
    int cnt;
    Heap() {
        cnt = 0;
    }
    void swap(int x, int y) {
        int t = mem[x].f;
        mem[x].f = mem[y].f, mem[y].f = t;
        t = mem[x].s, mem[x].s = mem[y].s, mem[y].s = t;
    }
    void update(int x) {
        while(mem[x].f < mem[x >> 1].f) swap(x, x >> 1), x >>= 1;
    }
    void pushdown(int i) {
        if(i << 1 > cnt)
            return ;
        int t = i << 1;
        if(t < cnt && mem[t | 1].f > mem[t].f)
            t |= 1;
        if(mem[t].f < mem[i].f) {
            swap(t, i);
            pushdown(t);
        }
    }
    void insert(int x, int y) {
        mem[++cnt] = (Mem){x, y};
        if(cnt != 1) update(cnt);
    }
    void pop() {
        mem[1].f = mem[cnt].f, mem[1].s = mem[cnt].s;
        cnt--;
        pushdown(1);
    }
} ;

int n, m, s, dis[10086], h[10086], cnt;
bool vis[10086];

bool isdigit(char ch) {
    return (ch <= '9' && ch >= '0');
}

int read() {
    int ret;
    bool flag = 0;
    char ch;
    while(!isdigit(ch = getchar())) (ch == '-') && (flag = 1);
    for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
    return flag ? -ret : ret;
}

void addedge(int u,int v, int w) {
    ++cnt;
    edges[cnt].v = v;
    edges[cnt].w = w;
    edges[cnt].nex = h[u];
    h[u] = cnt;
}

void dij(int s) {
    for(int i = 1; i <= n; ++i) dis[i] = (int)1e9;
    dis[s] = 0;
    std::priority_queue<std::pair<int, int > > heap;
    //Heap heap;
    //heap.cnt = 0;
    // for(int i = 0; i <= m; ++i) heap.mem[i].f = 0, heap.mem[i].s = 0;
    // heap.insert(dis[s], s);
    heap.push(std::make_pair(dis[s], s));
    //for(int i = 1; i <= n; ++i) heap.insert(dis[i], i);
    while(!heap.empty()) {
        // int d = heap.mem[1].f;
        // int u = heap.mem[1].s;
        int u = heap.top().second;
        heap.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = h[u]; i; i = edges[i].nex)
            if(dis[edges[i].v] > dis[u] + edges[i].w) {
                dis[edges[i].v] = dis[u] + edges[i].w;
                if(!edges[i].v) heap.push(std::make_pair(dis[edges[i].v], edges[i].v));
            }
    }
}

int main() {
    n = read(), m = read(), s = read();
    for(int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        addedge(u, v, w);
    }
    dij(s);
    for(int i = 1; i <= n; ++i) printf("%d ", dis[i]);
    return 0;
}