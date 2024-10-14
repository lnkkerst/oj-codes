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
  int n, k;
  cin >> n >> k;
  map<int, multiset<int>> a;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a[x % k].insert(x);
  }
  for (int i = 0; i <= n; ++i) {
    if (!a[i % k].empty()) {
      auto it = a[i % k].upper_bound(i);
      if (it == a[i % k].begin()) {
        cout << i << endl;
        return;
      } else {
        a[i % k].erase(--it);
      }
    } else {
      cout << i << endl;
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
