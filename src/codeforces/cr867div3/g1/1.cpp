#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define int long long
using namespace std;

vector<int> b(1e6 + 10);

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int ans = 0;
  int ma = -1e9;
  for (auto &i : a) {
    cin >> i;
    ++b[i];
    ma = max(ma, i);
  }
  set<int> aa{a.begin(), a.end()};
  for (auto i : aa) {
    for (int j = 1; i * j * j <= ma; ++j) {
      int tmp = b[i];
      --b[i];
      if (b[i * j]) {
        tmp *= b[i * j];
        --b[i * j];
        if (b[i * j * j]) {
          ans += tmp * b[i * j * j];
        }
        ++b[i * j];
      }
      ++b[i];
    }
  }
  for (auto i : a) {
    --b[i];
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
