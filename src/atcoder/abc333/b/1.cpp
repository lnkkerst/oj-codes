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
  string a, b;
  cin >> a >> b;
  int a1 = abs(a[0] - a[1]);
  if (a1 > 2) {
    a1 = 5 - a1;
  }
  int b1 = abs(b[0] - b[1]);
  if (b1 > 2) {
    b1 = 5 - b1;
  }
  if (a1 == b1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
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
