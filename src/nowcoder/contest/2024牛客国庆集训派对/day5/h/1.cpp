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

constexpr int MAXA = 1e6;

void solve() {
  int n;
  cin >> n;
  vector<int> b(MAXA + 1);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    ++b[x];
  }
  int ans = 0;
  for (int x = 1; x <= MAXA; ++x) {
    for (int i = 1; i * x <= MAXA; ++i) {
      ans += b[x] * b[i] * b[i * x];
    }
  }
  cout << ans << endl;
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
