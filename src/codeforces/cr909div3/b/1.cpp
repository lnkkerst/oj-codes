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
#define endl "\n"

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  set<int> b;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      b.insert(i);
      b.insert(n / i);
    }
  }
  int ans = 0;
  for (auto k : b) {
    vector<int> b;
    for (int i = 0; i < n / k; ++i) {
      int t = 0;
      for (int j = 0; j < k; ++j) {
        t += a[k * i + j];
      }
      b.emplace_back(t);
    }
    int ma = *max_element(b.begin(), b.end());
    int mi = *min_element(b.begin(), b.end());
    ans = max(ans, ma - mi);
  }
  cout << ans << endl;
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
