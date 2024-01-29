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
  int n, x;
  cin >> x >> n;
  set<int> fr;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      fr.insert(i);
      fr.insert(x / i);
    }
  }
  int ans = 1;
  for (auto i : fr) {
    if (x / i >= n) {
      ans = max(ans, i);
    }
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
