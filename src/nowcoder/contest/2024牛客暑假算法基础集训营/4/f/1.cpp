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

#define int __int128_t
using ll = long long;

void solve() {
  int n;
  ll _n;
  cin >> _n;
  n = _n;
  auto calc = [&](int n) {
    int da = n * (n - 1) / 2;
    int xiao = 0;
    if (n % 2 == 0) {
      int tmp = n / 2;
      xiao = tmp * (tmp + 1) / 2 + tmp * (tmp - 1) / 2;
    } else {
      int tmp = n / 2;
      xiao = tmp * (tmp + 1);
    }
    return da - xiao;
  };
  int l = 3, r = 1e12;
  while (l < r) {
    int mid = (l + r) / 2;
    if (calc(mid) >= n) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << (ll)r + ((n & 1) && !(r & 1)) << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ll t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
