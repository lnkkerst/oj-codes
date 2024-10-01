#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
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

string hashS(const vector<int> &a) {
  string res = "";
  for (auto i : a) {
    res = res + "*" + to_string(i);
  }
  return res;
}

vector<int> getE(int n) {
  vector<int> res(n + 1);
  for (int i = 1; i <= n; ++i) {
    res[i] = i;
  }
  return res;
}

vector<int> calc(const vector<int> &a, const vector<int> &b) {
  int n = a.size() - 1;
  vector<int> c(n + 1);
  for (int i = 1; i <= n; ++i) {
    c[i] = a[b[i]];
  }
  return c;
}

void print(const vector<int> &a) {
  int n = a.size() - 1;
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << ' ';
  }
  cout << endl;
}

void solve1(int n, int m, vector<vector<int>> &a) {
  set<string> s;
  function<void(vector<int>, int)> dfs = [&](vector<int> cur, int step) {
    if (step == m + 1) {
      return;
    }
    s.insert(hashS(cur));
    dfs(cur, step + 1);
    cur = calc(cur, a[step]);
    s.insert(hashS(cur));
    dfs(cur, step + 1);
  };
  for (int i = 1; i <= m; ++i) {
    s.insert(hashS(a[i]));
    dfs(a[i], i + 1);
  }
  cout << s.size() << endl;
}

struct Node {
  string h;
  vector<int> a;
  int pos;
  bool operator<(const Node &b) const {
    return h < b.h;
  }
  bool operator==(const Node &b) const {
    return h == b.h;
  }
};

struct NodeHash {
  std::size_t operator()(const Node &n) const {
    std::size_t h1 = std::hash<std::string>{}(n.h);
    return h1;
  }
};

void solve2(int n, int m, vector<vector<int>> &a) {
  set<Node> s;
  set<string> as;
  for (int i = 1; i <= m; ++i) {
    s.insert({hashS(a[i]), a[i], i});
    as.insert(hashS(a[i]));
  }
  for (int qwq = 1; qwq <= m; ++qwq) {
    decltype(s) ns;
    for (auto &i : s) {
      for (int j = i.pos + 1; j <= m; ++j) {
        auto cur = calc(i.a, a[j]);
        auto ch = hashS(cur);
        if (as.find(ch) == as.end()) {
          as.insert(ch);
          if (j != m) {
            ns.insert({ch, cur, j});
          }
        } else {
          if (j != m) {
            ns.insert({ch, cur, j});
          }
        }
      }
    }
    s = ns;
  }
  cout << as.size() << endl;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(m + 1, vector<int>(n + 1));
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }
  set<Node> s;
  for (int i = 1; i <= m; ++i) {
    auto ns = s;
    for (auto &j : s) {
      auto cur = calc(j.a, a[i]);
      auto ch = hashS(cur);
      ns.insert({ch, cur, i});
    }
    ns.insert({hashS(a[i]), a[i], i});
    s = ns;
  }
  cout << s.size() << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}
