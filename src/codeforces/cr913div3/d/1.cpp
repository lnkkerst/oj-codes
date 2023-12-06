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
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto &[l, r] : a) {
    cin >> l >> r;
  }
  int l = 0, r = 1e12;
  for (int qwq = 1; qwq <= 100; ++qwq) {
    int k = (l + r) / 2;
    int cl = 0, cr = 0;
    bool fl = true;
    for (int i = 0; i < n; ++i) {
      cl -= k;
      cr += k;
      if (cl > a[i].second || cr < a[i].first) {
        fl = false;
        break;
      }
      cl = max(cl, a[i].first);
      cr = min(cr, a[i].second);
    }
    if (fl) {
      r = k;
    } else {
      l = k + 1;
    }
  }
  cout << r << endl;
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
