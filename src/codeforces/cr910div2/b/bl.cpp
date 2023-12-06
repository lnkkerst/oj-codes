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
  deque<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  reverse(a.begin(), a.end());
  int last = a[0];
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] <= last) {
      continue;
    }
    while (a[i] > last) {
      ++ans;
      a[i] -= last;
    }
    a[i] += last;
    a[i] /= 2;
    last = a[i];
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
