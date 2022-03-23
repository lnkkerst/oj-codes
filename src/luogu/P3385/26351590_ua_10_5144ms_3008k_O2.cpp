#include <bits/stdc++.h>
using namespace std;

struct Node {
    int dis, inq, h;
    int cnt;
} nodes[100010];

struct Edge {
    int to, w;
    int nex;
} edges[500010];

int n, m, s;
int cnt;

void addedge(int u, int v, int w) {
    edges[++cnt].nex = nodes[u].h;
    edges[cnt].to = v;
    edges[cnt].w = w;
    nodes[u].h = cnt;
}

bool spfa(int start) {
    priority_queue<pair<int, int >, vector<pair<int, int > >, greater<pair<int, int > > > q;
    for(int i = 1; i <= n; ++i) nodes[i].dis = 2147483647;
    nodes[start].dis = 0, nodes[start].inq = 1, ++nodes[start].cnt;
    q.push(make_pair(nodes[start].dis, start));
    while(!q.empty()) {
        int u = q.top().second;
        nodes[u].inq = 0;
        q.pop();
        for(int i = nodes[u].h; i; i = edges[i].nex) {
            int v = edges[i].to;
            if(nodes[v].dis > nodes[u].dis + edges[i].w) {
                nodes[v].dis = nodes[u].dis + edges[i].w;
                if(!nodes[v].inq) {
                    nodes[v].inq = 1;
                    ++nodes[v].cnt;
                    if(nodes[v].cnt == n) return 1;
                    q.push(make_pair(nodes[v].dis, v));
                }
            }
        }
    }
    return 0;
}

void work() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        addedge(u, v, w);
        if(w >= 0) addedge(v, u, w);
    }
    printf("%s\n", spfa(1) ? "YE5" : "N0");
}

int main() {
    cin >> s;
    while(s--) work();
    return 0;
}