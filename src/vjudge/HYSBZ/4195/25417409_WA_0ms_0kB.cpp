#include <cstdio>
#include <hash_map>
#include <iostream>
using namespace std;
using namespace __gnu_cxx;

int f[4000001];

int find(int x) {
  return f[x] == x ? x : f[x] = find(f[x]);
}

void merge(int u, int v) {
  f[find(u)] = find(v);
}

bool query(int u, int v) {
  return find(u) == find(v);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, cnt = 0;
    hash_map<int, int> id;
    vector<pair<int, int>> a;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      f[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
      int u, v, opt;
      cin >> u >> v >> opt;
      if (!id[u]) {
        id[u] = ++cnt;
      }
      if (!id[v]) {
        id[v] = ++cnt;
      }
      if (opt) {
        merge(id[u], id[v]);
      } else {
        a.push_back(make_pair(id[u], id[v]));
      }
    }
    bool fl = 1;
    for (int i = 0; i < (int)a.size(); ++i) {
      if (query(a[i].first, a[i].second)) {
        puts("NO");
        fl = 0;
      }
    }
    if (fl) {
      puts("YES");
    }
  }
  return 0;
}
