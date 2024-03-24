#pragma GCC optimize(2)
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
using namespace std;

#define int long long

constexpr int MOD = 1e9 + 7;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<int> f(23);
  f[0] = 1;
  for (int i = 1; i <= 20; ++i) {
    f[i] = f[i - 1] * i;
    f[i] %= MOD;
  }

  int n, t;
  cin >> n >> t;

  vector<pair<int, int>> a(n);
  for (auto &[x, y] : a) {
    cin >> x >> y;
  }

  map<int, map<int, map<int, int>>> bk;

  auto calc = [&](vector<int> cnt) {
    sort(cnt.begin() + 1, cnt.end());
    if (bk[cnt[1]][cnt[2]][cnt[3]]) {
      return bk[cnt[1]][cnt[2]][cnt[3]];
    }
    int ans = 0;
    function<void(vector<int>, int)> dfs = [&](vector<int> cnt, int pre) {
      // cout << pre << ' ';
      // for (int i = 1; i <= 3; ++i) {
      //   cout << cnt[i] << ' ';
      // }
      // cout << endl;
      if (!cnt[1] && !cnt[2] && !cnt[3]) {
        ++ans;
        ans %= MOD;
        return;
      }
      for (int i = 1; i <= 3; ++i) {
        if (cnt[i] > 0 && i != pre) {
          --cnt[i];
          dfs(cnt, i);
          ++cnt[i];
        }
      }
    };
    dfs(cnt, -1);
    for (int i = 1; i <= 3; ++i) {
      ans *= f[cnt[i]];
      ans %= MOD;
    }
    bk[cnt[1]][cnt[2]][cnt[3]] = ans;
    return ans;
  };

  // cout << calc({0, 5, 3, 2}) << endl;

  int ans = 0;

  for (int i = 0; i < (1 << n); ++i) {
    int tot = 0;
    vector<int> cnt(4);
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        tot += a[j].first;
        ++cnt[a[j].second];
      }
    }
    // for (int i = 1; i <= 3; ++i) {
    //   cout << cnt[i] << ' ';
    // }
    // cout << endl;
    if (tot == t) {
      ans += calc(cnt);
      ans %= MOD;
    }
  }
  cout << ans << endl;
}
