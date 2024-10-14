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
  int n, m;
  cin >> n >> m;
  m = min(n, m);
  vector<int> a(n + 1);
  vector<int> b(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  sort(b.begin() + 1, b.end());
  vector<vector<vector<int>>> dp(
    n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1)));
  for (int x = 1; x <= n; ++x) {
    int numa = x / 2;
    int numb = (x + 1) / 2;
    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= m; ++j) {
        int bana = numa + i - j;
        int banb = numb + j - i;
      }
    }
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
