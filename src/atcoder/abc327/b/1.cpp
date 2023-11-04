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

#define int long long

__int128_t qmi(int x, int k) {
  int res = 1;
  while (k) {
    if (k & 1) {
      res *= x;
    }
    x *= x;
    k >>= 1;
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  int cur = 1;
  while (true) {
    auto x = qmi(cur, cur);
    if (x == n) {
      cout << cur << endl;
      return;
    }
    if (x > n) {
      cout << -1 << endl;
      return;
    }
    ++cur;
  }
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
