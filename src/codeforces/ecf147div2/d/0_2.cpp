#include <algorithm>
#include <iostream>
#include <vector>
#define int long long

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (auto &i : a) {
    cin >> i.first;
  }
  for (auto &i : a) {
    cin >> i.second;
  }
  {
    int tmp = 0;
    for (auto &i : a) {
      tmp += i.second - i.first + 1;
    }
    if (tmp < k) {
      cout << -1 << endl;
      return;
    }
  }
  sort(a.begin(), a.end(), [](pair<int, int> &a, pair<int, int> &b) -> bool {
    return a.first < b.first;
  });
  int pos = 0;
  int cnt = 0;
  int cld = 0;
  int ans = 0;
  for (auto &i : a) {
    int sz = i.second - i.first + 1;
    if (sz == 1) {
      ++cnt;
      ans += i.second - pos;
      pos = i.second;
      continue;
    }
    int cs1 = min(k - cld, sz) - 1 + (i.first - pos) + 2;
    if (k - cld <= cnt) {
      int cs2 = (k - cld) * 2;
      ans += min(cs1, cs2);
      cout << ans << endl;
      return;
    }
    ans += cs1;
    cld += sz;
    pos = i.second;
    if (cld >= k) {
      cout << ans << endl;
      return;
    }
  }
  cout << ans + (k - cld) * 2 << endl;
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
