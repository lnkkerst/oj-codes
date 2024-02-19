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
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int end = n - 1;
  int ans = 0;
  while (true) {
    set<int> b;
    for (int i = 0; i <= end; ++i) {
      b.insert(a[i]);
    }
    int id = 0;
    map<int, int> mp, rmp;
    for (auto x : b) {
      mp[x] = ++id;
      rmp[mp[x]] = x;
    }
    int tot = id;
    b.clear();
    for (int i = end; i >= 0; --i) {
      if (b.size() == tot - 1 && b.find(mp[a[i]]) == b.end()) {
        b.clear();
        ++ans;
        end = i - 1;
        continue;
      }
      b.insert(mp[a[i]]);
    }
    if (end == -1) {
      break;
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
