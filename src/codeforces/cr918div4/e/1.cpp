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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (int i = 0; i < n; i += 2) {
    a[i] = -a[i];
  }
  set<int> b{0};
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    cur += a[i];
    if (b.find(cur) != b.end()) {
      cout << "YES" << endl;
      return;
    }
    b.insert(cur);
  }
  cout << "NO" << endl;
  return;
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
