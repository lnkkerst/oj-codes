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
  vector<int> a(n), b(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  int mi = 2e9, mip = 0, mit = 0;
  for (int i = 0; i < n; ++i) {
    auto it = lower_bound(a.begin(), a.end(), b[i]);
    if (it != a.end()) {
      int x = *it;
      if (abs(x - b[i]) < mi) {
        mi = abs(x - b[i]);
        mip = i;
        mit = x;
      }
    }
    if (it != a.begin()) {
      --it;
      int x = *it;
      if (abs(x - b[i]) < mi) {
        mi = abs(x - b[i]);
        mip = i;
        mit = x;
      }
    }
  }
  auto it = find(a.begin(), a.end(), mit);
  swap(a[it - a.begin()], a[mip]);
  for (auto i : a) {
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
