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
  string s, e;
  int n;
  cin >> s >> e >> n;

  auto process_time = [&](string s) {
    int h = 0, m = 0;
    int pos = 0;
    while (pos < s.size() && s[pos] != ':') {
      h *= 10;
      h += s[pos] - '0';
      ++pos;
    }
    ++pos;
    while (pos < s.size()) {
      m *= 10;
      m += s[pos] - '0';
      ++pos;
    }
    return h * 60 + m;
  };

  int m = process_time(e) - process_time(s);

  vector<int> w(n + 1), v(n + 1), a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> w[i] >> v[i] >> a[i];
  }
  vector<int> dp(m + 1);
  for (int i = 1; i <= n; ++i) {
    if (!a[i]) {
      for (int j = w[i]; j <= m; ++j) {
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
      }
    } else {
      int base = 1;
      int k = a[i];
      while (k > base) {
        int cw = w[i] * base;
        int cv = v[i] * base;
        for (int j = m; j >= cw; --j) {
          dp[j] = max(dp[j], dp[j - cw] + cv);
        }
        k -= base;
        base <<= 1;
      }
      int cw = w[i] * k;
      int cv = v[i] * k;
      for (int j = m; j >= cw; --j) {
        dp[j] = max(dp[j], dp[j - cw] + cv);
      }
    }
  }
  cout << *max_element(dp.begin() + 1, dp.end()) << endl;
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
