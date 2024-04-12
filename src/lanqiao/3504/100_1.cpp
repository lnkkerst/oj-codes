#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<int>> e(n + 1);
  vector<int> c(n + 1);
  vector<map<int, int> *> a(n + 1, nullptr);
  for (int i = 1; i <= n; ++i) {
    int u;
    cin >> c[i] >> u;
    e[u].emplace_back(i);
  }
  int ans = 0;
  function<void(int, int)> dfs = [&](int u, int pre) {
    if (e[u].empty()) {
      a[u] = new map<int, int>();
    }
    vector<map<int, int> *> p;
    for (auto v : e[u]) {
      if (v == pre) {
        continue;
      }
      dfs(v, u);
      p.emplace_back(a[v]);
    }
    sort(p.begin(), p.end(), [&](map<int, int> *a, map<int, int> *b) {
      return a->size() > b->size();
    });
    for (auto i : p) {
      if (a[u] == nullptr) {
        a[u] = i;
      } else {
        for (auto [k, v] : *i) {
          (*a[u])[k] += v;
        }
        i->clear();
      }
    }
    ++(*a[u])[c[u]];
    int t = a[u]->begin()->second;
    bool fl = true;
    for (auto [_, v] : *a[u]) {
      if (v != t) {
        fl = false;
        break;
      }
    }
    if (fl) {
      ++ans;
    }
  };
  dfs(1, 0);
  cout << ans << endl;
}
