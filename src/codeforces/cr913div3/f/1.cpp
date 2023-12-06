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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int ans = 1e9;
  int cnt = 0;
  vector<int> b;
  for (int i = 0; i < n - 1; ++i) {
    cnt += a[i] > a[i + 1];
    if (a[i] > a[i + 1]) {
      b.emplace_back(i);
    }
  }
  if (b.size() == 0) {
    ans = min(ans, 0);
  } else if (b.size() == 1) {
    if (a.back() <= a.front()) {
      ans = min(ans, n - (b.front() + 1));
      ans = min(ans, (b.front() + 1) + 2);
    }
  }
  b.clear();
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] < a[i + 1]) {
      b.emplace_back(i);
    }
  }
  if (b.size() == 0) {
    ans = min(ans, 1);
  } else if (b.size() == 1) {
    if (a.back() >= a.front()) {
      ans = min(ans, n - (b.front() + 1) + 1);
      ans = min(ans, (b.front() + 1) + 1);
    }
  }
  if (ans == 1e9) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
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
