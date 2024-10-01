#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define int long long

using namespace std;

constexpr int MOD = 998244353;

struct Node {
  int go[2];
  int v;
  Node() {
    go[0] = go[1] = -1;
    v = 0;
  }
};

int qmi(int x, int k, int p = MOD) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res = res * x % p;
    }
    x = x * x % p;
    k >>= 1;
  }
  return res;
}

int inv(int x, int p = MOD) {
  return qmi(x, p - 2, p);
}

void solve() {
  int n;
  cin >> n;
  vector<Node> tr(1);
  auto add = [&](int x) {
    int cur = 0;
    for (int i = 29; i >= 0; --i) {
      int b = (x >> i) & 1;
      if (tr[cur].go[b] == -1) {
        tr[cur].go[b] = tr.size();
        tr.emplace_back(Node());
      }
      ++tr[cur].v;
      cur = tr[cur].go[b];
    }
    ++tr[cur].v;
  };
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    add(x);
  }
  int ans = 0;
  function<void(int, int)> dfs = [&](int cur, int k) {
    if (tr[cur].go[0] != -1 && tr[cur].go[1] != -1) {
      int i = k + 1;
      ans += (2 * (i / 2) + 1) * tr[tr[cur].go[0]].v * tr[tr[cur].go[1]].v;
      ans += 2 * ((i + 1) / 2) * tr[tr[cur].go[0]].v * tr[tr[cur].go[1]].v;
      ans %= MOD;
    }
    if (tr[cur].go[0] == -1 && tr[cur].go[1] == -1) {
      int i = k + 1;
      ans += i * tr[cur].v * tr[cur].v;
      ans %= MOD;
    }
    if (tr[cur].go[0] != -1) {
      dfs(tr[cur].go[0], k);
    }
    if (tr[cur].go[1] != -1) {
      dfs(tr[cur].go[1], k + 1);
    }
  };
  dfs(0, 0);
  ans = ans * inv(n) % MOD;
  ans = ans * inv(n) % MOD;
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
