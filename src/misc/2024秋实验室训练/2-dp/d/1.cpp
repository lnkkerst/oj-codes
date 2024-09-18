#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct Trie {
  int rt = 0;
  vector<array<int, 26>> go;
  vector<int> win, lose;

  Trie() {
    go.emplace_back();
    win.emplace_back();
    lose.emplace_back();
  }

  void insert(const string &s) {
    int u = rt;
    for (auto c : s) {
      int x = c - 'a';
      if (!go[u][x]) {
        go[u][x] = go.size();
        go.emplace_back();
        win.emplace_back();
        lose.emplace_back();
      }
      u = go[u][x];
    }
  }

  void process() {
    function<void(int)> dfs = [&](int u) {
      bool fl = true;
      for (int i = 0; i < 26; ++i) {
        int v = go[u][i];
        if (v) {
          fl = false;
          dfs(v);
          if (!win[v]) {
            win[u] = true;
          }
          if (!lose[v]) {
            lose[u] = true;
          }
        }
      }
      if (fl) {
        win[u] = false;
        lose[u] = true;
      }
    };
    dfs(rt);
  }
};

void solve() {
  int n, k;
  cin >> n >> k;
  Trie tr;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    tr.insert(s);
  }
  tr.process();
  if (!tr.win[tr.rt]) {
    cout << "Second" << endl;
  } else {
    if (tr.lose[tr.rt]) {
      cout << "First" << endl;
    } else {
      if (k & 1) {
        cout << "First" << endl;
      } else {
        cout << "Second" << endl;
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
