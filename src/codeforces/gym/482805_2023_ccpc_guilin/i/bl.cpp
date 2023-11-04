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

#define int long long

struct Node {
  int l, r;
  int mex;
  bool operator<(const Node &b) const { return r < b.r; }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  auto getMex = [](vector<int> a) -> int {
    int n = a.size() - 1;
    sort(a.begin() + 1, a.end());
    if (a[1] != 1) {
      return 1;
    }
    for (int i = 2; i <= n; ++i) {
      if (a[i] - a[i - 1] > 1) {
        return a[i - 1] + 1;
      }
    }
    return a[n] + 1;
  };
  int ma = -1;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      auto ta = vector<int>{a.begin() + i - 1, a.begin() + j + 1};
      auto s = set<int>();
      for (int k = i; k <= j; ++k) {
        s.insert(a[k]);
      }
      ma = max(ma, (int)s.size() - getMex(ta));
    }
  }
  cout << ma << endl;
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
