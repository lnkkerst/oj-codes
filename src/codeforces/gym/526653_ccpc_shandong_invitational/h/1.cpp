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

#define int long long
#define vector deque

struct Pos {
  int x, y;
};

struct Pair {
  int l, r;
  Pair(int _l = -1, int _r = -1): l(_l), r(_r) {}
};

void solve() {
  int n;
  cin >> n;
  vector<Pos> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  int m;
  cin >> m;
  vector<Pos> b(m + 1);
  for (int i = 1; i <= m; ++i) {
    cin >> b[i].x >> b[i].y;
  }
  vector<Pair> xe;
  vector<Pair> ye;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if ((a[i].x == a[j].x && abs(a[i].y - a[j].y) == 1)
          || (a[i].y == a[j].y && abs(a[i].x - a[j].x) == 1)) {
        cout << -1 << endl;
        return;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    int left = -1;
    int right = -1;
    int top = -1;
    int bottom = -1;
    for (int j = i + 1; j <= n; ++j) {
      if (a[i].x == a[j].x) {
        if (a[j].y > a[i].y) {
          if (right == -1) {
            right = j;
          } else if (a[j].y < a[right].y) {
            right = j;
          }
        } else {
          if (left == -1) {
            left = j;
          } else if (a[j].y > a[left].y) {
            left = j;
          }
        }
      }
      if (a[i].y == a[j].y) {
        if (a[j].x > a[i].x) {
          if (bottom == -1) {
            bottom = j;
          } else if (a[j].x < a[bottom].x) {
            bottom = j;
          }
        } else {
          if (top == -1) {
            top = j;
          } else if (a[j].x > a[top].x) {
            top = j;
          }
        }
      }
    }
    for (int j = 1; j <= m; ++j) {
      if (b[j].x == a[i].x) {
        if (b[j].y > a[i].y) {
          if (right != -1 && b[j].y < a[right].y) {
            right = -1;
          }
        } else {
          if (left != -1 && b[j].y > a[left].y) {
            left = -1;
          }
        }
      }
      if (b[j].y == a[i].y) {
        if (b[j].x > a[i].x) {
          if (bottom != -1 && b[j].x < a[bottom].x) {
            bottom = -1;
          }
        } else {
          if (top != -1 && b[j].x > a[top].x) {
            top = -1;
          }
        }
      }
    }
    if (left != -1) {
      xe.emplace_back(i, left);
    }
    if (right != -1) {
      xe.emplace_back(i, right);
    }
    if (top != -1) {
      ye.emplace_back(i, top);
    }
    if (bottom != -1) {
      ye.emplace_back(i, bottom);
    }
  }
  // cout << "xe: " << endl;
  // for (auto [l, r] : xe) {
  //   cout << l << ' ' << r << endl;
  // }
  // cout << "ye: " << endl;
  // for (auto [l, r] : ye) {
  //   cout << l << ' ' << r << endl;
  // }
  int uN = xe.size();
  int vN = ye.size();
  xe.emplace_front(0, 0);
  ye.emplace_front(0, 0);
  vector<vector<int>> g(uN + 1, vector<int>(vN + 1));
  for (int i = 1; i <= uN; ++i) {
    for (int j = 1; j <= vN; ++j) {
      int top = min(a[ye[j].l].x, a[ye[j].r].x);
      int bottom = max(a[ye[j].l].x, a[ye[j].r].x);
      int left = min(a[xe[i].l].y, a[xe[i].r].y);
      int right = max(a[xe[i].l].y, a[xe[i].r].y);
      // cout << top << ' ' << bottom << ' ' << left << ' ' << right << endl;
      if (a[xe[i].l].x > top && a[xe[i].l].x < bottom && a[ye[j].l].y > left
          && a[ye[j].l].y < right) {
        g[i][j] = 1;
      }
    }
  }
  vector<int> linker(vN + 1, -1);
  vector<int> used(vN + 1);
  function<bool(int)> dfs = [&](int u) {
    for (int v = 1; v <= vN; ++v) {
      if (g[u][v] && !used[v]) {
        used[v] = true;
        if (linker[v] == -1 || dfs(linker[v])) {
          linker[v] = u;
          return true;
        }
      }
    }
    return false;
  };
  int cnt = 0;
  for (int u = 1; u <= uN; ++u) {
    used = vector<int>(vN + 1);
    if (dfs(u)) {
      ++cnt;
    }
  }
  // for (int i = 1; i <= uN; ++i) {
  //   for (int j = 1; j <= vN; ++j) {
  //     cout << g[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  cout << uN + vN - cnt << endl;
  vector<int> uxe(uN + 1), vxe(vN + 1);
  for (int v = 1; v <= vN; ++v) {
    int u = linker[v];
    if (u == -1) {
      continue;
    }
    // cout << xe[u].l << ' ' << xe[u].r << ' ' << ye[v].l << ' ' << ye[v].r
    //      << endl;
    cout << a[xe[u].l].x << ' ' << a[ye[v].l].y << endl;
    uxe[u] = 1;
    vxe[v] = 1;
  }
  for (int i = 1; i <= uN; ++i) {
    if (uxe[i]) {
      continue;
    }
    cout << a[xe[i].l].x << ' ' << min(a[xe[i].l].y, a[xe[i].r].y) + 1 << endl;
  }
  for (int i = 1; i <= vN; ++i) {
    if (vxe[i]) {
      continue;
    }
    cout << min(a[ye[i].l].x, a[ye[i].r].x) + 1 << ' ' << a[ye[i].l].y << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
