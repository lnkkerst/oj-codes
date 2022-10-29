#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      a.emplace_back(x);
    }
    sort(a.begin(), a.end(), greater<>());
    --k;
    int cnt = 0;
    int need = 0;
    for (auto i : a) {
      if (i == a[k]) {
        ++cnt;
      }
    }
    for (int i = k; i >= 0; --i) {
      if (a[i] == a[k]) {
        ++need;
      }
    }
    int ans = 1;
    for (int i = 1; i <= cnt; ++i) {
      ans *= i;
      ans %= MOD;
    }
    for (int i = 1; i <= need; ++i) {
      ans /= i;
      ans %= MOD;
    }
    for (int i = 1; i <= cnt - need; ++i) {
      ans /= i;
      ans %= MOD;
    }
    cout << ans << endl;
  }
  return 0;
}