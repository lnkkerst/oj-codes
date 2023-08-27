#pragma GCC optimize(2)

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

#define int long long

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e12;

void solve() {
  string s, t;
  cin >> s >> t;
  int n;
  cin >> n;
  map<char, map<char, int>> mp;
  for (auto i = 'a'; i <= 'z'; ++i) {
    for (auto j = 'a'; j <= 'z'; ++j) {
      mp[i][j] = INF;
    }
  }
  for (int i = 1; i <= n; ++i) {
    char u, v;
    int w;
    cin >> u >> v >> w;
    mp[u][v] = min(mp[u][v], w);
  }
  if (s.length() != t.length()) {
    cout << -1 << endl;
    return;
  }
  for (auto i = 'a'; i <= 'z'; ++i) {
    mp[i][i] = 0;
  }
  for (auto k = 'a'; k <= 'z'; ++k) {
    for (auto i = 'a'; i <= 'z'; ++i) {
      for (auto j = 'a'; j <= 'z'; ++j) {
        if (mp[i][j] > mp[i][k] + mp[k][j]) {
          mp[i][j] = mp[i][k] + mp[k][j];
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < s.length(); ++i) {
    int tmp = INF;
    char ta = s[i];
    for (auto j = 'a'; j <= 'z'; ++j) {
      int nt = mp[s[i]][j] + mp[t[i]][j];
      if (nt < tmp) {
        tmp = nt;
        ta = j;
      }
    }
    s[i] = t[i] = ta;
    ans += tmp;
  }
  if (ans >= INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl << s << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
