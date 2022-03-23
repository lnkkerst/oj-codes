#include <bits/stdc++.h>
using namespace std;

struct Node {
    int dis, inq, h;
} nodes[50010];

struct Edge {
    int to, w;
    int nex;
} edges[200010];

struct eedge {
    int x, y, a, b;
} edge[100010];

int n, m;
int cnt;
int ans = 0x3fffffff;

bool cmp(eedge a, eedge b) {
    return a.a < b.a;
}

void addedge(int u, int v, int w) {
    edges[++cnt].nex = nodes[u].h;
    edges[cnt].to = v;
    edges[cnt].w = w;
    nodes[u].h = cnt;
}
queue<int > q;
void spfa(int s, int t) {
    nodes[s].inq = nodes[t].inq = 1;
    q.push(s), q.push(t);
    while(!q.empty()) {
        int u = q.front();
        nodes[u].inq = 0;
        q.pop();
        for(int i = nodes[u].h; i; i = edges[i].nex) {
            int v = edges[i].to;
            if(nodes[v].dis > max(nodes[u].dis, edges[i].w)) {
                nodes[v].dis = max(nodes[u].dis, edges[i].w);
                if(!nodes[v].inq) {
                    nodes[v].inq = 1;
                    q.push(v);
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) cin >> edge[i].x >> edge[i].y >> edge[i].a >> edge[i].b;
    sort(edge + 1, edge + m + 1, cmp);
    for(int i = 1; i <= n; ++i) nodes[i].dis = 0x3fffffff;
    nodes[1].dis = 0, nodes[1].inq = 1, q.push(1);
    for(int i = 1; i <= m; ++i) {
        addedge(edge[i].x, edge[i].y, edge[i].b);
        addedge(edge[i].y, edge[i].x, edge[i].b);
        spfa(edge[i].x, edge[i].y);
        ans = min(ans, nodes[n].dis + edge[i].a);
    }
    printf("%d\n", ans == 0x3fffffff ? -1 : ans);
    return 0;
}