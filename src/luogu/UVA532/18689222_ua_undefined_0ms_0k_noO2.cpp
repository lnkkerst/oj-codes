#include <cstdio>
#include <cctype>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 110
#define INF 0x7fffffff
#define num ch - '0'

struct Map {
    char c;
    int n;
} map[MAXN][MAXN];

struct Node {
    std::vector<struct Edge> edges;
    int dis;
} nodes [MAXN + 1];

struct Edge {
    Node *from, *to;
    int w;
} ;

int k, n, m, s, e, tot;

void add(int u, int v, int w) {
    Edge e;
    e.from = &nodes[u];
    e.to = &nodes[v];
    e.w = w;
    nodes[u].edges.push_back(e);
}

int dijkstra(int start, int end) {
    for(int i = 1; i <= tot; ++i)
        nodes[i].dis = INF;

    std::priority_queue<std::pair<int, Node*> > q;

    q.push(std::make_pair(0, &nodes[start]));
    nodes[start].dis = 0;

    while(!q.empty()) {
        std::pair<int, Node *> p = q.top();
        q.pop();

        if(-p.first != p.second->dis)
            continue;
        Node *v = p.second;

        for(int i = 0; i < (int)v->edges.size(); ++i) {
            Edge *e = &v->edges[i];
            if(e->to->dis > v->dis + e->w) {
                e->to->dis = v->dis + e->w;
                q.push(std::make_pair(-e->to->dis, e->to));
            }
        }
    }
    return nodes[end].dis;
}

int main() {
    while(1) {
        for(int i = 1; i <= tot; i++)
            nodes[i].edges.clear();
        tot = 0;
        memset(map, '#', sizeof(map));
        scanf("%d%d%d", &k, &m, &n);
        // getchar();
        if(k == 0 && n == 0 && m == 0)
            return 0;
        char tmp;
        for(int kk = 1; kk <= k; ++kk) {
            for(int i = 1; i <= m; ++i) {
                for(int j = 1; j <= n; ++j) {
                    std::cin >> tmp;
                    if(tmp != '#') {
                        ++tot;
                        if(i > 1 && map[i - 1][j].c != '#') {
                            add(map[i -1][j].n, tot, 1);
                            add(tot, map[i - 1][j].n, 1);
                        }   
                        if(j > 1 && map[i][j - 1].c != '#') {
                            add(map[i][j - 1].n, tot, 1);
                            add(tot, map[i][j - 1].n, 1);
                        }
                        if(k > 1 && map[i][j].c != '#') {
                            add(map[i][j].n, tot, 1);
                            add(tot, map[i][j].n, 1);
                        }
                        if(tmp == 'S')
                            s = tot;
                        if(tmp == 'E')
                            e = tot;
                    }
                    map[i][j].c = tmp;
                    map[i][j].n = tot;
                }
                // getchar();
            }
        }
        int ans = dijkstra(s, e);
        if(ans == INF)
            printf("Trapped!\n");
        else 
            printf("Escaped in %d minute(s).\n", ans);
    }
}