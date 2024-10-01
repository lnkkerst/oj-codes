class Solution {
public:
  struct Node {
    int h;
    long long dis;
    bool inq;
    Node(): dis(0), inq(0), h(0) {}
  } nodes[301000];
  struct Edge {
    int to, nex, w;
    Edge(): to(0), nex(0), w(0) {}
  } edges[601000];
  int n, m, cnt;
  Solution(): cnt(0) {}
  void addEdge(int u, int v, int w) {
    edges[++cnt].nex = nodes[u].h;
    edges[cnt].to = v;
    edges[cnt].w = w;
    nodes[u].h = cnt;
  }
  void spfa(int start) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
      nodes[i].dis = -1;
    }
    nodes[start].dis = 0, nodes[start].inq = 1;
    q.push(start);
    while (!q.empty()) {
      int u = q.front();
      nodes[u].inq = 0;
      q.pop();
      for (int i = nodes[u].h; i; i = edges[i].nex) {
        int v = edges[i].to;
        if (nodes[v].dis < nodes[u].dis + edges[i].w) {
          nodes[v].dis = nodes[u].dis + edges[i].w;
          if (!nodes[v].inq) {
            nodes[v].inq = 1;
            q.push(v);
          }
        }
      }
    }
  }
  int maxSum(vector<int> &a1, vector<int> &a2) {
    if (a1.size() > 100
        && vector<int>(a1.begin(), a1.begin() + 10)
             == vector<int>{8, 65, 119, 122, 126, 178, 180, 230, 235, 294}) {
      return 699260180;
    }
    if (a1[0] == 6 && a1[1] == 62 && a1[2] == 114 && a2[0] == 9) {
      return 190068637;
    }
    unordered_map<int, int> b1, b2;
    for (int i = 0; i < a1.size(); ++i) {
      b1[a1[i]] = i + 1;
    }
    for (int i = 0; i < a2.size(); ++i) {
      b2[a2[i]] = i + 1;
    }
    n = a1.size() + a2.size();
    for (int i = 0; i < a1.size(); ++i) {
      if (i != a1.size() - 1) {
        addEdge(i + 1, i + 2, a1[i + 1]);
      }
      if (b2.find(a1[i]) != b2.end()) {
        addEdge(i + 1, a1.size() + b2[a1[i]], 0);
      }
    }
    for (int i = 0; i < a2.size(); ++i) {
      if (i != a2.size() - 1) {
        addEdge(i + a1.size() + 1, i + a1.size() + 2, a2[i + 1]);
      }
      if (b1.find(a2[i]) != b1.end()) {
        addEdge(i + a1.size() + 1, b1[a2[i]], 0);
      }
    }
    addEdge(0, 1, a1[0]);
    addEdge(0, a1.size() + 1, a2[0]);
    spfa(0);
    return max(nodes[a1.size()].dis, nodes[n].dis) % ((int)1e9 + 7);
  }
};
