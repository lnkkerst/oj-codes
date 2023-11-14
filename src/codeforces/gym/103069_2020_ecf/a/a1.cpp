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
  string s;
  cin >> s;
  int n = s.length();
  int m = 62;
  vector<int> dp1(n + 1);
  vector<int> last(m + 1, -1);
  vector<int> cnt(m + 1);
  vector<vector<int>> dp2(n + 1, vector<int>(m + 1));
  vector<vector<int>> su2(m + 1, vector<int>(m + 1));
  auto su1 = last;
  auto dp3 = dp2;
  auto su3 = su2;
  auto dp4 = dp2;
  for (auto &i : s) {
    if (i >= '0' && i <= '9') {
      i = i - '0' + 1;
    } else if (i >= 'a' && i <= 'z') {
      i = i - 'a' + 10 + 1;
    } else {
      i = i - 'A' + 10 + 26 + 1;
    }
    ++cnt[i];
  }
  s = " " + s;
  for (int i = n; i >= 1; --i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i] == j) {
        continue;
      }
      int nx = last[j];
      if (nx == -1) {
        continue;
      }
      dp2[i][j] = su2[s[i]][j] + dp1[nx];
      dp3[i][j] = su3[s[i]][j] + dp2[nx][s[i]];
      dp4[i][j] = dp3[nx][s[i]];
    }
    su1[s[i]]++;
    dp1[i] = su1[s[i]];
    for (int j = 1; j <= m; ++j) {
      if (s[i] == j) {
        continue;
      }
      su2[s[i]][j] = dp2[i][j];
      su3[s[i]][j] = dp3[i][j];
    }
    last[s[i]] = i;
  }
  int ans = 0;
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (j == s[i]) {
        continue;
      }
      int num = i - 1;
      if (num < 2) {
        continue;
      }
      int pre, suf;
      pre = num * (num - 1) / 2;
      pre -= res;
      int st = cnt[s[i]] * (num - cnt[s[i]]) + cnt[j] * (num - cnt[j]);
      pre = pre - st + cnt[s[i]] * cnt[j];
      suf = dp4[i][j];
      ans += (pre * suf);
    }
  }
  cout << ans << endl;
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
