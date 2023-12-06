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

void solve() {
  int n;
  cin >> n;
  deque<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int cnt = 0;
  for (int i = 1; i < a.size(); ++i) {
    cnt += a[i - 1] >= a[i];
  }
  int ans = cnt;
  for (int i = 0; i < a.size(); ++i) {
    if (i == 0) {
      ++cnt;
    }
    if (i >= 1) {
      cnt -= a[i - 1] >= a[i];
    }
    if (i >= 2) {
      cnt += a[i - 2] <= a[i - 1];
    }
    ans = min(ans, cnt);
  }
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
