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

template <typename T>
std::vector<T> create_nd_vector(size_t size) {
  return std::vector<T>(size);
}

template <typename T, typename... Sizes>
auto create_nd_vector(size_t first, Sizes... sizes) {
  return std::vector<decltype(create_nd_vector<T>(sizes...))>(
    first, create_nd_vector<T>(sizes...));
}

void solve() {
  int n;
  cin >> n;
  vector<string> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = " " + a[i];
  }
  auto dp = create_nd_vector<int>(n + 1, n + 1, n + 1, n + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; i + j - 1 <= n; ++j) {
      for (int k = 1; k <= n; ++k) {
        for (int l = 1; k + l - 1 <= n; ++l) {
          if (i == 1 && k == 1) {
            dp[i][j][k][l] = a[j][l] == '#';
            continue;
          }
          int mi = max(i, k);
          for (int t = 1; t < i; ++t) {
            mi = min(mi, dp[t][j][k][l] + dp[i - t][j + t][k][l]);
          }
          for (int t = 1; t < k; ++t) {
            mi = min(mi, dp[i][j][t][l] + dp[i][j][k - t][l + t]);
          }
          dp[i][j][k][l] = mi;
        }
      }
    }
  }
  cout << dp[n][1][n][1] << endl;
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
