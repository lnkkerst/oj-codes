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

void solve() {
  int n, q, tc;
  cin >> n >> q >> tc;
  vector<int> a(n + 1);
  auto p = a;
  auto pr = a;
  int sm = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.begin() + n + 1);
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i - 1] + a[i];
    sm += p[i];
    pr[i] = pr[i - 1] + p[i];
  }
  while (q--) {
    int m;
    cin >> m;
    int l = 0, r = n;
    for (int qwq = 1; qwq <= 30; ++qwq) {
      int mid = (l + r + 1) / 2;
      if (mid * tc <= m) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    cout << tc + p[n - l + 1 - 1] << endl;
  }
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
