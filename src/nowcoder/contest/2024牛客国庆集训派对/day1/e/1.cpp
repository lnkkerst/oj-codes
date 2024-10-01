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

constexpr int MAXN = 1e18;

void solve() {
  vector<int> a{1};
  for (int i = 2; i * i * i <= MAXN; ++i) {
    int x = i;
    int y = x * x * x;
    a.emplace_back(y);
    while (y <= (MAXN + x) / (i * i)) {
      x = i * i * y - x;
      swap(x, y);
      if (y <= MAXN) {
        a.emplace_back(y);
      }
    }
  }
  sort(a.begin(), a.end());
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << upper_bound(a.begin(), a.end(), n) - a.begin() << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
