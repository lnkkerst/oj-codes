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
  vector<int> h(n + 1), v(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> h[i] >> v[i];
  }
  vector<int> ans(n + 1);
  stack<int> s;
  for (int i = 1; i <= n; ++i) {
    while (!s.empty() && h[s.top()] < h[i]) {
      s.pop();
    }
    if (!s.empty()) {
      ans[s.top()] += v[i];
    }
    s.push(i);
  }
  s = stack<int>();
  for (int i = n; i >= 1; --i) {
    while (!s.empty() && h[s.top()] < h[i]) {
      s.pop();
    }
    if (!s.empty()) {
      ans[s.top()] += v[i];
    }
    s.push(i);
  }
  int mx = 0;
  for (int i = 1; i <= n; ++i) {
    mx = max(mx, ans[i]);
  }
  cout << mx << endl;
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
