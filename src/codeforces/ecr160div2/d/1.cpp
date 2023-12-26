#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bits/extc++.h>
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
using namespace __gnu_pbds;

#define int long long

constexpr int MOD = 998244353;

int qmi(int x, int k, int q = MOD) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res = res * x % q;
    }
    k >>= 1;
    x = x * x % q;
  }
  return res;
}

using Tree = tree<int, null_type, less<int>, rb_tree_tag,
                  tree_order_statistics_node_update>;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> nm(n);
  vector<int> su(n + 2);
  vector<int> dp(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  deque<int> st;
  nm[n - 1] = n;
  su[n] = 1;
  for (int pos = n - 1; pos >= 0; --pos) {
    while (!st.empty() && a[st.back()] > a[pos]) {
      st.pop_back();
    }
    nm[pos] = st.empty() ? n : st.back();
    st.emplace_back(pos);
    int np = nm[pos];
    int cur = su[pos + 1] - su[np + 1];
    cur %= MOD;
    if (np != n) {
      cur = cur + dp[np];
      cur %= MOD;
      dp[pos] = su[np] - su[np + 1] + dp[np];
      dp[pos] %= MOD;
    }
    su[pos] = cur + su[pos + 1];
    su[pos] %= MOD;
  }
  int ans = 0;
  int mi = a[0];
  for (int i = 0; i < n; ++i) {
    mi = min(mi, a[i]);
    if (a[i] == mi) {
      ans = ans + su[i] - su[i + 1];
      ans %= MOD;
    }
  }
  cout << (ans + MOD) % MOD << endl;
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
