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

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto &[x, y] : a) {
    cin >> x >> y;
  }
  bool fla = false;
  bool fl = true;
  for (auto [x, y] : a) {
    if (x < 0) {
      fl = false;
    }
  }
  if (fl) {
    fla = true;
  }
  fl = true;
  for (auto [x, y] : a) {
    if (x > 0) {
      fl = false;
    }
  }
  if (fl) {
    fla = true;
  }
  fl = true;
  for (auto [x, y] : a) {
    if (y > 0) {
      fl = false;
    }
  }
  if (fl) {
    fla = true;
  }
  fl = true;
  for (auto [x, y] : a) {
    if (y < 0) {
      fl = false;
    }
  }
  if (fl) {
    fla = true;
  }
  if (fla) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
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
