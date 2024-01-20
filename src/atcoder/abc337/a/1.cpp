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
  int cx = 0, cy = 0;
  for (int i = 1; i <= n; ++i) {
    int x, y;
    cin >> x >> y;
    cx += x;
    cy += y;
  }
  if (cx > cy) {
    cout << "Takahashi" << endl;
  } else if (cx == cy) {
    cout << "Draw" << endl;

  } else {
    cout << "Aoki" << endl;
  }
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
