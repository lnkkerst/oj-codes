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
  int x, s;
  cin >> x >> s;
  int ans = 1;
  for (int i = 0; i < 32; ++i) {
    int bx = ((x >> i) & 1);
    int bs = ((s >> i) & 1);
    if (bs == 0 && bx == 1) {
      ans *= 0;
    }
    if (bs == 1 && bx == 1) {
      ans *= 2;
    }
  }
  if (x == s) {
    --ans;
  }
  cout << ans << endl;
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
