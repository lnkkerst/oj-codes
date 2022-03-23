#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node;
struct Edge;
struct Map;

struct Node {
    bool visDfs;
    bool visBfs;
    vector<Edge> edges;
    Node() : visDfs(false), visBfs(false) {}
};

struct Edge {
    int u, v;
    explicit Edge(int _u = 0, int _v = 0) : u(_u), v(_v) {}
};

struct Map {
    vector<Node> nodes;
    explicit Map(int _n = 0) : nodes(vector<Node>(_n + 1)) {}
    void addEdge(int u, int v) {
        nodes[u].edges.emplace_back(Edge(u, v));
    }
    void sortEdge() {
        for(auto &i : nodes) {
            sort(i.edges.begin(), i.edges.end(), [](Edge a, Edge b) -> bool {
                return a.v < b.v;
            });
        }
    }
    void dfs(int no) {
        for(auto &i : nodes) {
            i.visDfs = false;
        }
        dfsIn(no);
    }
    void bfs(int no) {
        for(auto &i : nodes) {
            i.visBfs = false;
        }
        bfsIn(no);
    }
private:
    void dfsIn(int now) {
        if(nodes[now].visDfs) return ;
        nodes[now].visDfs = true;
        cout << now << ' ';
        for(auto i : nodes[now].edges) {
            dfsIn(i.v);
        }
    }
    void bfsIn(int start) {
        queue<int> q;
        q.push(start);
        nodes[start].visBfs = true;
        while(!q.empty()) {
            int now = q.front();
            q.pop();
            cout << now << ' ';
            for(auto i : nodes[now].edges) {
                if(!nodes[i.v].visBfs) {
                    q.push(i.v);
                    nodes[i.v].visBfs = true;
                }
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Map ma(n);
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        ma.addEdge(u, v);
    }
    ma.sortEdge();
    ma.dfs(1);
    cout << endl;
    ma.bfs(1);
    return 0;
}