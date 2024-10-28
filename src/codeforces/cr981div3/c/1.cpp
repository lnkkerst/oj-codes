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
  vector<int> a(n + 10);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= (n) / 2; ++i) {
    if ((a[i] == a[i - 1]) + (a[n - i + 1] == a[n - i + 2])
        > (a[i] == a[n - i + 2]) + (a[n - i + 1] == a[i - 1])) {
      swap(a[i], a[n - i + 1]);
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == a[i - 1]) {
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
  cin >> t;
  while (t--) {
    solve();
  }
}
