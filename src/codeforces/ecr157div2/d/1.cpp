#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
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
  for (int i = 1; i < n; ++i) {
    cin >> a[i];
    a[i] ^= a[i - 1];
  }
  for (int d = 0; d < 30; ++d) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] & (1ll << d)) {
        ++cnt;
      } else {
        --cnt;
      }
    }
    if (cnt > 0) {
      for (int i = 0; i < n; ++i) {
        a[i] ^= (1ll << d);
      }
    }
  }
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
