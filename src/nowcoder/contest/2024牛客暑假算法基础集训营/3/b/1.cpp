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

int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

void solve() {
  int n, d;
  cin >> n >> d;
  set<int> a;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a.insert(x);
  }
  int g = *a.begin();
  for (auto x : a) {
    g = gcd(g, x);
  }
  cout << min(d % g, ((g - d) % g + g) % g) << endl;
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
