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
  int n, k;
  cin >> n >> k;
  set<int> s;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      s.insert(i);
      s.insert(n / i);
    }
  }
  auto it = s.begin();
  --k;
  while (it != s.end() && k--) {
    ++it;
  }
  if (it == s.end()) {
    cout << -1 << endl;
  } else {
    cout << *it << endl;
  }
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
