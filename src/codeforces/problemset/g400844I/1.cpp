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
  int a, b;
  cin >> a >> b;
  vector<int> w(a + b + 1), l(a + b + 1), r(a + b + 1);
  int cnt = 0;
  function<void(int, int, int)> dfs = [&](int a, int b, int num) {
    if (b > 0) {
      --b;
      w[num] = 2;
    } else {
      a--;
      w[num] = 1;
    }
    int sum = a + b * 2;
    int lb = b / 2;
    int rb = b - b / 2;
    int la = sum / 2 - lb * 2;
    int ra = a - la;
    if (la < 0 || ra < 0) {
      cout << -1;
      exit(0);
    }
    if (la || lb) {
      l[num] = ++cnt;
      dfs(la, lb, cnt);
    }
    if (ra || rb) {
      r[num] = ++cnt;
      dfs(ra, rb, cnt);
    }
  };
  dfs(a, b, ++cnt);
  for (int i = 1; i <= a + b; ++i) {
    cout << w[i] << ' ' << l[i] << ' ' << r[i] << endl;
  }
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
