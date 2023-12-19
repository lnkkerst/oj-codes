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
  for (auto &i : a) {
    cin >> i;
  }
  Tree b;
  int cnt = 0;
  int ans = 1;
  b.insert(a[0]);
  for (int i = 0; i < n; ++i) {
    int ls = b.order_of_key(a[i]);
    int rs = b.size() - ls;
    cnt += rs;
    cnt %= MOD;
    if (a[i] > a[i - 1]) {
      ans *= 2;
      ans %= MOD;
    } else {
      ans += cnt * 2;
      ans %= MOD;
    }
  }
  cout << ans << endl;
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
