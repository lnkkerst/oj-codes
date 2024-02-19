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
  int a, b, r;
  cin >> a >> b >> r;
  if (a > b) {
    swap(a, b);
  }
  bool fl = true;
  int x = 0;
  for (int i = 60; i >= 0; --i) {
    int ba = (a >> i) & 1;
    int bb = (b >> i) & 1;
    if (ba == bb) {
      continue;
    }
    if (fl) {
      fl = false;
      continue;
    }
    if (ba == 1) {
      continue;
    }
    if ((x | (1ll << i)) > r) {
      continue;
    }
    x |= (1ll << i);
    a ^= (1ll << i);
    b ^= (1ll << i);
  }
  cout << abs(a - b) << endl;
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
