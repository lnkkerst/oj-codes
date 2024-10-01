#include <iostream>
#include <vector>
using namespace std;

struct Node;
struct Edge;
struct Map;

struct Node {
  int maxNo;
  bool vis;
  vector<Edge> edges;
  Node(): maxNo(-1), vis(false) {}
};

struct Edge {
  int u, v;
  explicit Edge(int _u = 0, int _v = 0): u(_u), v(_v) {}
};

struct Map {
  vector<Node> nodes;
  explicit Map(int _n = 0): nodes(vector<Node>(_n + 1)) {}
  void addEdge(int u, int v) {
    nodes[u].edges.emplace_back(Edge(u, v));
  }
  void update(int no) {
    dfs(no, no);
  }

private:
  void dfs(int now, int no) {
    if (nodes[now].vis) {
      return;
    }
    nodes[now].vis = true;
    nodes[now].maxNo = no;
    for (auto i : nodes[now].edges) {
      dfs(i.v, no);
    }
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  Map ma(n);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    ma.addEdge(v, u);
  }
  for (int i = n; i >= 1; --i) {
    ma.update(i);
  }
  for (int i = 1; i <= n; ++i) {
    cout << ma.nodes[i].maxNo << ' ';
  }
  return 0;
}
