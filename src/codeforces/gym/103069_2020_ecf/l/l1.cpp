#pragma GCC optimize(2)
#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
#define mod 1000000007
#define maxn 200002
#define int long long
using namespace std;

vector<int> mp(1e6 + 1);
map<int, int> mm;
int vis[maxn * 10], p[maxn], cnt, n;
int a[maxn], b[maxn], num[maxn];
int shu[maxn][50], jil[maxn][50];
int t[maxn], ans, ma = 0, cur[maxn];

int qmi(int x, int k, int p = mod) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res = (res * x) % mod;
    }
    x = (x * x) % mod;
    k >>= 1;
  }
  return res;
}

void solve() {
  cin >> n;
  // n = 1e5;
  vis[0] = vis[1] = 1;
  for (int i = 2; i <= 1000000; ++i) {
    if (!vis[i]) {
      ++cnt;
      p[cnt] = i;
      if (p[cnt] > 1000) {
        mm[p[cnt]] = 1;
      }
    }
    for (int j = 1; j <= cnt && i * p[j] <= 1000000; ++j) {
      vis[i * p[j]] = 1;
      if (i % p[j] == 0) {
        break;
      }
    }
  }

  // cout << cnt << endl;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    // a[i] = 999983;
  }

  if (n == 1) {
    cout << 1 << endl;
    return;
  }

  for (int i = 1; i <= n; ++i) {
    int tmp = a[i];
    int res = 1;
    // cout << tmp << endl;
    while (tmp > 1) {
      if (mm[tmp] == 1) {
        ma = max(ma, p[res]);
        num[i]++;
        jil[i][num[i]]++;
        shu[i][num[i]] = tmp;
        break;
      }
      // cout << tmp;1
      if (tmp % p[res] == 0) {
        tmp /= p[res];
        if (p[res] == shu[i][num[i]]) {
          jil[i][num[i]]++;
        } else {
          // mp[p[res]]++;
          ma = max(ma, p[res]);
          num[i]++;
          jil[i][num[i]]++;
          shu[i][num[i]] = p[res];
        }
      } else {
        res++;
      }
    }
  }

  int ami = 1e9, ama = -1;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= num[i]; ++j) {
      jil[i][j] %= 2;
      if (jil[i][j] == 1) {
        mp[shu[i][j]]++;
        int t = shu[i][j];
        ama = max(ama, t);
        ami = min(ami, t);
      }
    }
  }

  ans = 1;
  for (int i = ami; i <= ama; ++i) {
    int mi = min(mp[i], n - mp[i]);
    ans = (ans * qmi(i, mi)) % mod;
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  // cin >> t;
  while (T--) {
    solve();
  }
}
