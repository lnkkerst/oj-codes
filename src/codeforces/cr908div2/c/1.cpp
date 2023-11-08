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
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 2);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  if (a[n] == n) {
    cout << "Yes" << endl;
    return;
  }
  unordered_map<int, int> b;
  int cur = n;
  for (int qwq = 1; qwq <= k; ++qwq) {
    if (a[cur] > n) {
      cout << "No" << endl;
      return;
    }
    if (b[cur]) {
      cout << "Yes" << endl;
      return;
    }
    b[cur] = true;
    int nx = cur - a[cur] - 1;
    if (nx < 0) {
      nx += (a[cur] / n + 1) * n;
      nx = nx % n;
    }
    ++nx;
    cur = nx;
  }
  cout << "Yes" << endl;
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
