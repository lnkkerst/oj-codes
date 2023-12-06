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
  deque<int> a(3);
  for (int i = 0; i < 3; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < 3; ++i) {
    int ma = max(a[1], a[2]);
    int mi = min(a[1], a[2]);
    int x = a[0];
    x += mi;
    ma -= mi;
    if (ma % 2 == 0) {
      cout << 1 << ' ';
    } else {
      cout << 0 << ' ';
    }
    x = a.front();
    a.pop_front();
    a.emplace_back(x);
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
