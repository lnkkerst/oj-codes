#include <iostream>
#include <vector>
#include <queue>

#define int long long

using namespace std;

struct Edge {
    int u, v, w;

    explicit Edge(int _u = 0, int _v = 0, int _w = 0) : u(_u), v(_v), w(_w) {}
};

struct Node {
    int dis;
    bool inq;
    bool vis;
    vector<Edge> edges;

    explicit Node(int _dis = 2e9, int _inq = false, int _vis = false) : dis(_dis), inq(_inq), vis(_vis) {}
};

struct Map {
    vector<Node> nodes;

    Node &operator[](size_t x) {
        return nodes[x];
    }

    explicit Map(int _n = 0) : nodes(vector<Node>(_n + 1)) {}

    void addEdge(int u, int v, int w) {
        nodes[u].edges.emplace_back(Edge(u, v, w));
    }

    void dijkstra(int start) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > h;
        nodes[start].dis = 0;
        h.push(make_pair(nodes[start].dis, start));
        while (!h.empty()) {
            auto now = h.top();
            h.pop();
            if (nodes[now.second].vis) {
                continue;
            }
            nodes[now.second].vis = true;
            for (auto i: nodes[now.second].edges) {
                if (nodes[i.v].dis > nodes[now.second].dis + i.w) {
                    nodes[i.v].dis = nodes[now.second].dis + i.w;
                    if (!nodes[i.v].vis) {
                        h.push(make_pair(nodes[i.v].dis, i.v));
                    }
                }
            }
        }
    }
};

signed main() {

    int n, m;
    cin >> n >> m;
    Map ma(n * 4);
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        for(int j = 0; j < 4; ++j) {
            ma.addEdge(u + n * j, v + n * j, w);
            ma.addEdge(v + n * j, u + n * j, w);
        }
        ma.addEdge(u, v + n, w * 2);
        ma.addEdge(v, u + n, w * 2);
        ma.addEdge(u + n * 2, v + n * 3, w * 2);
        ma.addEdge(v + n * 2, u + n * 3, w * 2);
        ma.addEdge(u, v + n * 2, 0);
        ma.addEdge(v, u + n * 2, 0);
        ma.addEdge(u + n, v + n * 3,0);
        ma.addEdge(v + n, u + n * 3, 0);
    }
    ma.dijkstra(1);
    for (int i = 2; i <= n; ++i) {
        cout << min(ma[i].dis, ma[i + n * 3].dis) << ' ';
    }
    return 0;
}