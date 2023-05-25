#include <algorithm>
#include <iostream>
#include <vector>
#define int long long
using namespace std;

constexpr int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }
  int ans = 1;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int i = 0; i < b.size(); ++i) {
    auto it = upper_bound(a.begin(), a.end(), b[i]);
    if (it == a.end()) {
      ans = 0;
      break;
    }
    ans *= (n - (it - a.begin())) - (n - i) + 1;
    ans %= MOD;
  }
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
