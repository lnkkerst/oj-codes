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
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int ans = 2e9;
  int i = 0;
  for (int j = 0; j < n; ++j) {
    if (a[j] < a[i]) {
      i = j;
    }
  }
  int t = 0;
  for (int j = i; j < n; ++j) {
    t += abs(a[j] - (j - i + 1));
  }
  for (int j = 0; j < i; ++j) {
    t += abs(a[j] - (n - i + j + 1));
  }
  ans = min(ans, t);
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
