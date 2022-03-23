#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 220010

int n, m, k;

struct Node {
    std::vector<struct Edge> edges;
    int dist;
} nodes[MAXN + 1];

struct Edge {
    Node *from, *to;
    int w;
};

void add(int u, int v, int w) {
    Edge e;
    e.from = &nodes[u];
    e.to = &nodes[v];
    e.w = w;
    nodes[u].edges.push_back(e);
}

void dijkstra(int start) {
    for(int i = 1; i <= MAXN; i++)
        nodes[i].dist = __INT_MAX__;

    std::priority_queue<std::pair<int, Node*> > q;

    q.push(std::make_pair(0, &nodes[start]));
    nodes[start].dist = 0;

    while(!q.empty()) {
        std::pair<int, Node *> p = q.top();
        q.pop();

        if(-p.first != p.second->dist)
            continue;
        Node *v = p.second;

        for(int i = 0; i < (int)v->edges.size(); i++) {
            Edge *e = &v->edges[i];
            if(e->to->dist > v->dist + e->w) {
                e->to->dist = v->dist + e->w;
                q.push(std::make_pair(-e->to->dist, e->to));
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);

    for(int i = 1; i <= m; i++) {
        int t1, t2, t3;

        scanf("%d%d%d", &t1, &t2, &t3);
        add(t1, t2, t3);
        add(t2, t1, t3);

        for(int j = 1; j <= k; j++) {
            add(j * n + t1, j * n + t2, t3);
            add(j * n + t2, j * n + t1, t3);
            add((j - 1) * n + t1, j * n + t2, 0);
            add((j - 1) * n + t2, j * n + t1, 0);
        }
    }

    int tmp = n;
    dijkstra(1);
    int ans = nodes[tmp].dist;

    for(int i = 1; i <= k; i++)
        ans = std::min(ans, nodes[i * n + tmp].dist);

    printf("%d", ans);

    return 0;
}