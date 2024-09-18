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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    p[i] = p[i - 1] + a[i];
  }
  auto get_sum = [&](int l, int r) {
    return p[r] - p[l - 1];
  };
  vector<vector<int>> dmi(n + 1, vector<int>(n + 1));
  auto dma = dmi;
  for (int k = 2; k <= n; ++k) {
    for (int i = 1; i + k - 1 <= n; ++i) {
      int l = i;
      int r = i + k - 1;
      dmi[l][r] = 1e12;
      dma[l][r] = 0;
      for (int j = l + 1; j <= r; ++j) {
        dmi[l][r] = min(dmi[l][r], dmi[l][j - 1] + dmi[j][r] + get_sum(l, r));
        dma[l][r] = max(dma[l][r], dma[l][j - 1] + dma[j][r] + get_sum(l, r));
      }
    }
  }
  cout << dmi[1][n] << endl;
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
