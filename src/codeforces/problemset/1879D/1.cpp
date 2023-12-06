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

constexpr int MOD = 998244353;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int ans = 0;
  for (int k = 0; k < 30; ++k) {
    int pre = 0;
    int prels[2] = {0, 0};
    int prel[2] = {1, 0};
    for (int i = 1; i <= n; ++i) {
      pre += (a[i] >> k) & 1;
      pre %= MOD;
      prels[pre & 1] += i;
      prels[pre & 1] %= MOD;
      prel[pre & 1]++;
      ans += (i * prel[!(pre & 1)] - prels[!(pre & 1)]) % MOD * (1 << k) % MOD;
      ans = (ans % MOD + MOD) % MOD;
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
