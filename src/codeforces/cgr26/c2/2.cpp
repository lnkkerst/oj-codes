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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> mi(n + 1), ma(n + 1);
  auto mic = mi, mac = ma;
  for (int i = 1; i <= n; ++i) {
    mi[i] = min(mi[i - 1] + a[i], abs(mi[i - 1] + a[i]));
    mi[i] = min(mi[i], min(ma[i - 1] + a[i], abs(ma[i - 1] + a[i])));

    ma[i] = max(ma[i - 1] + a[i], abs(ma[i - 1] + a[i]));
    ma[i] = max(ma[i], max(mi[i - 1] + a[i], abs(mi[i - 1] + a[i])));
  }
  cout << ma[n] << endl;
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
