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
  int l, r;
  cin >> l >> r;
  if (r < l * 2) {
    cout << 0 << endl;
    return;
  }
  int ans
    = (r - l * 2 + 1) * (r - l * 2 + 1) - ((r - l * 2 + 1) * (r - l * 2)) / 2;
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
