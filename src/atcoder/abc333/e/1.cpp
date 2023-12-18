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
  vector<pair<int, int>> a(n);
  for (auto &[t, x] : a) {
    cin >> t >> x;
  }
  map<int, int> b;
  int tot = 0;
  for (auto [t, x] : a) {
    if (t == 1) {
      ++b[x];
      ++tot;
    } else {
      if (!b[x]) {
        cout << -1 << endl;
        return;
      }
      --b[x];
    }
  }
  b.clear();
  tot = 0;
  reverse(a.begin(), a.end());
  int ansk = 0;
  vector<int> ans;
  for (auto [t, x] : a) {
    if (t == 1) {
      if (b[x]) {
        ans.emplace_back(1);
        --b[x];
        --tot;
      } else {
        ans.emplace_back(0);
      }
    } else {
      ++b[x];
      ++tot;
    }
    ansk = max(ansk, tot);
  }
  cout << ansk << endl;
  reverse(ans.begin(), ans.end());
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << endl;
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
