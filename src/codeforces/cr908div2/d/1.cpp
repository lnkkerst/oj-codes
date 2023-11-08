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

void solve() {
  int n, m;
  cin >> n >> m;
  deque<int> a(n), c(n + m);
  multiset<int, greater<>> b;
  for (auto &i : a) {
    cin >> i;
  }
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    b.insert(x);
  }
  sort(b.begin(), b.end());
  int len = 1;
  vector<int> d(n + 1);
  d[len] = a[0];
  for (int i = 1; i < n; ++i) {
    if (a[i] > d[len]) {
      auto it = b.lower_bound(d[len]);
      d[++len] = a[i];
    } else {
      int l = 1, r = len, pos = 0;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (d[mid] < a[i]) {
          pos = mid;
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
      d[pos + 1] = a[i];
    }
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
