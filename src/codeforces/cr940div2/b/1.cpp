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
  if (n == 1) {
    cout << k << endl;
    return;
  }
  vector<int> a;
  int cx = 0;
  for (int i = 0; i <= 30 && a.size() < n; ++i) {
    int x = 1ll << i;
    if (k >= x) {
      cx += x;
      k -= x;
    }
  }
  a.emplace_back(cx);
  if (a.size() == n) {
    if (k & 1) {
      a[1] += 1;
      a[0] += k - 1;
    } else {
      a[0] += k;
    }
  } else {
    a.emplace_back(k);
    while (a.size() < n) {
      a.emplace_back(0);
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
  cin >> t;
  while (t--) {
    solve();
  }
}
