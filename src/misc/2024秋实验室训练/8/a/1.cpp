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
  string s;
  cin >> s;
  s = " " + s;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    a[i] = s[i] - '0';
  }
  auto b = a;
  sort(b.begin() + 1, b.begin() + 1 + n);
  int cur = 1;
  vector<int> d1, d2;
  vector<int> ans(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (b[cur] == a[i]) {
      ++cur;
      d1.emplace_back(a[i]);
      ans[i] = 1;
    } else {
      d2.emplace_back(a[i]);
      ans[i] = 2;
    }
  }
  auto sd2 = d2;
  sort(sd2.begin(), sd2.end());
  if (d2 != sd2) {
    cout << "-" << endl;
    return;
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i];
  }
  cout << endl;
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
