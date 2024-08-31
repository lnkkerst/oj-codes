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

int lcd(int a, int b) {
  return a * b / gcd(a, b);
}

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  int g = gcd(n, m);
  int gn = n / g;
  int gm = m / g;
  while (q--) {
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    int bs;
    if (sx == 1) {
      bs = (sy - 1) / gn;
    } else {
      bs = (sy - 1) / gm;
    }
    int be;
    if (ex == 1) {
      be = (ey - 1) / gn;
    } else {
      be = (ey - 1) / gm;
    }
    cout << (be == bs ? "YES" : "NO") << endl;
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
