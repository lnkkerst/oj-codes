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
  int n, x;
  cin >> n >> x;
  vector<int> ans;
  for (int i = 0; i <= n; ++i) {
    if (i - (n - i) == x) {
      ans.emplace_back(i);
    }
  }
  if (ans.size() != 1) {
    cout << -1 << endl;
  } else {
    cout << ans.front() << ' ' << n - ans.front() << endl;
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
