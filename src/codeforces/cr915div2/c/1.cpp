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

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool fl = true;
  for (int i = 1; i < n; ++i) {
    if (s[i] < s[i - 1]) {
      fl = false;
      break;
    }
  }
  if (fl) {
    cout << 0 << endl;
    return;
  }
  vector<int> b(n);
  string t;
  int cur = 0;
  for (int j = 'z'; j >= 'a'; j--) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == j && i >= cur) {
        t += j;
        cur = i;
        b[i] = true;
      }
    }
  }
  int ans = t.size();
  auto ma = *max_element(t.begin(), t.end());
  for (auto i : t) {
    if (i == ma) {
      --ans;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (b[i]) {
      s[i] = t.back();
      t.pop_back();
    }
  }
  for (int i = 1; i < n; ++i) {
    if (s[i] < s[i - 1]) {
      cout << -1 << endl;
      return;
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
