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
  int ans = 0;
  sort(a.begin(), a.end());
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    ans += tot - a[i];
    ans += a[i] * (n - 1);
    ans += a[i] * i - cur;
    ans += (tot - cur - a[i]) - a[i] * (n - i - 1);
    cur += a[i];
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
