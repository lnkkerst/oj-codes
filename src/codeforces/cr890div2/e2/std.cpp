#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long long ll;
typedef long double ld;

using namespace std;

const int maxn = 1000000;

vector<int> g[maxn];
int s[maxn];
ll ans = 0;
vector<ll> b;
ll closest;

template <int len = 1>
void subset_sum(int n) {
  if (n >= len) {
    subset_sum<std::min(len * 2, maxn)>(n);
    return;
  }

  bitset<len> dp;

  dp[0] = 1;
  for (ll x : b) {
    dp = dp | (dp << x);
  }

  ll cv = n;
  closest = 0;
  for (int i = 0; i <= n; i++) {
    if (dp[i] && abs(i - (n - i)) < cv) {
      closest = i;
      cv = abs(i - (n - i));
    }
  }
}

ll solve(vector<ll> &a) {
  if (a.empty()) {
    return 0;
  }

  sort(allr(a));
  ll cs = 0;
  for (ll x : a) {
    cs += x;
  }

  if (a[0] * 2 >= cs) {
    return a[0];
  }

  int n = gsize(a);
  a.push_back(0);

  b.clear();
  int pi = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] != a[i - 1]) {
      ll cnt = i - pi;
      ll x = a[i - 1];

      ll j = 1;
      while (j < cnt) {
        b.push_back(x * j);
        cnt -= j;
        j *= 2;
      }
      b.push_back(x * cnt);

      pi = i;
    }
  }

  subset_sum(cs);
  return closest;
}

void dfs(int v, int p = -1) {
  vector<ll> a;
  s[v] = 1;

  for (int u : g[v]) {
    if (u == p) {
      continue;
    }
    dfs(u, v);
    s[v] += s[u];

    a.push_back(s[u]);
  }

  ll x = solve(a);
  ans += x * (s[v] - 1 - x);
  a.clear();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    g[x - 1].push_back(i);
  }

  dfs(0);

  cout << ans << nl;
}
