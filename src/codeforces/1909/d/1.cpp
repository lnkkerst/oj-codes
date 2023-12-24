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

int sgn(int x) { return x < 0 ? -1 : x > 0; }

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  set<int> b;
  for (auto &i : a) {
    cin >> i;
    i -= k;
    b.insert(sgn(i));
  }
  if (b.size() != 1) {
    cout << -1 << endl;
    return;
  }
  if (*b.begin() == 0) {
    cout << 0 << endl;
    return;
  }
  if (*b.begin() == -1) {
    for (auto &i : a) {
      i = -i;
    }
  }
  int g = a[0];
  for (int i = 1; i < n; ++i) {
    g = gcd(g, a[i]);
  }
  int ans = 0;
  for (auto i : a) {
    ans += (i / g) - 1;
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
