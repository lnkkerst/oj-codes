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

void solve() {
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  auto calc = [&](int l, int r) {
    auto ca = a;
    for (auto &i : ca) {
      i = min(i, r);
      i = max(i, l);
    }
    int res = 0;
    for (int i = 1; i < ca.size(); ++i) {
      res += abs(ca[i] - ca[i - 1]);
    }
    return res;
  };
  int ans = 0;
  for (auto i : a) {
    ans = max(ans, calc(i, i + d));
    ans = max(ans, calc(i - d, i));
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
