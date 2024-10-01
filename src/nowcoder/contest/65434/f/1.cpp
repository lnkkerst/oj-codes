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
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!a[i][j]) {
        for (int k = 1; i * k <= n && j * k <= m; ++k) {
          a[i * k][j * k] = i * j * k;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    deque<int> q;
    for (int j = 1; j <= m; ++j) {
      while (!q.empty() && a[i][q.back()] < a[i][j]) {
        q.pop_back();
      }
      q.push_back(j);
      if (q.front() <= j - k) {
        q.pop_front();
      }
      a[i][j] = a[i][q.front()];
    }
  }
  for (int j = 1; j <= m; ++j) {
    deque<int> q;
    for (int i = 1; i <= n; ++i) {
      while (!q.empty() && a[q.back()][j] <= a[i][j]) {
        q.pop_back();
      }
      q.push_back(i);
      if (q.front() <= i - k) {
        q.pop_front();
      }
      a[i][j] = a[q.front()][j];
      if (i >= k && j >= k) {
        ans = ans + a[i][j];
      }
    }
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  // cin >> t;
  t = 1;
  while (t--) {
    solve();
  }
}
