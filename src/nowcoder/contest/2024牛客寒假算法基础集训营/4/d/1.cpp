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
  int tot = 0;
  for (auto &i : a) {
    cin >> i;
    tot += i;
  }
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  int ans = 0;
  for (int x = 1; x <= (int)(2e5); ++x) {
    if (tot % x == 0 && tot / x >= n) {
      ++ans;
    }
  }
  cout << ans << endl;
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
