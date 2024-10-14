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
  int tot = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    tot += a[i];
  }
  vector<int> suf(n + 2);
  for (int i = n; i >= 2; --i) {
    suf[i] = suf[i + 1] + a[i];
  }
  sort(suf.begin() + 2, suf.begin() + n + 1, greater<>());
  cout << tot << ' ';
  for (int i = 2; i <= n; ++i) {
    tot += suf[i];
    cout << tot << ' ';
  }
  cout << endl;
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
