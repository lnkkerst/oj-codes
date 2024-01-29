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
  int n, k, m;
  cin >> n >> k >> m;
  string s;
  cin >> s;
  set<char> b;
  int cnt = 0;
  string ans;
  for (auto i : s) {
    b.insert(i);
    if (b.size() == k) {
      ++cnt;
      b.clear();
      ans += i;
    }
  }
  if (cnt >= n) {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
  for (char i = 'a'; i <= 'a' + k - 1; ++i) {
    if (b.find(i) == b.end()) {
      while (ans.length() != n) {
        ans += i;
      }
      cout << ans << endl;
      return;
    }
  }
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
