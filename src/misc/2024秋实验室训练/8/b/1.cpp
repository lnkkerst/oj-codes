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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int q;
  cin >> q;
  vector<int> modify(n + 1, 0);
  vector<int> b(q + 1);
  for (int i = 1; i <= q; ++i) {
    int op;
    cin >> op;
    if (op == 1) {
      int k, x;
      cin >> k >> x;
      a[k] = x;
      modify[k] = i;
    } else {
      cin >> b[i];
    }
  }
  vector<int> mx(q + 2);
  for (int i = q; i >= 0; --i) {
    mx[i] = max(mx[i + 1], b[i]);
  }
  for (int i = 1; i <= n; ++i) {
    a[i] = max(a[i], mx[modify[i]]);
  }
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << ' ';
  }
  cout << endl;
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
