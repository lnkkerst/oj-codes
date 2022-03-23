#include <iostream>
#include <vector>
#include <queue>
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
    explicit Node(int _dis = INT32_MAX, int _inq = false, int _vis = false) : dis(_dis), inq(_inq), vis(_vis) {}
};

struct Map {
    vector<Node> nodes;
    Node& operator[](size_t x) {
        return nodes[x];
    }
    explicit Map(int _n = 0) : nodes(vector<Node>(_n + 1)) {}
    void addEdge(int u, int v, int w) {
        nodes[u].edges.emplace_back(Edge(u, v, w));
    }
    void spfa(int start) {
        queue<int> q;
        q.push(start);
        nodes[start].inq = true;
        nodes[start].dis = 0;
        while(!q.empty()) {
            int now = q.front();
            q.pop();
            nodes[now].inq = false;
            for(auto i : nodes[now].edges) {
                int v = i.v;
                if(nodes[v].dis > nodes[now].dis + i.w) {
                    nodes[v].dis = nodes[now].dis + i.w;
                    if(!nodes[v].inq) {
                        nodes[v].inq = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    void dijkstra(int start) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > h;
        nodes[start].dis = 0;
        h.push(make_pair(nodes[start].dis, start));
        while(!h.empty()) {
            auto now = h.top();
            h.pop();
            if(nodes[now.second].vis) {
                continue;
            }
            nodes[now.second].vis = true;
            for(auto i : nodes[now.second].edges) {
                if(nodes[i.v].dis > nodes[now.second].dis + i.w) {
                    nodes[i.v].dis = nodes[now.second].dis + i.w;
                    if(!nodes[i.v].vis) {
                        h.push(make_pair(nodes[i.v].dis, i.v));
                    }
                }
            }
        }
    }
};

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    Map ma(n);
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        ma.addEdge(u, v, w);
    }
//    ma.spfa(s);
    ma.dijkstra(s);
    for(int i = 1; i <= n; ++i) {
        cout << ma[i].dis << ' ';
    }
    return 0;
}
