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
  int c1 = 0, c2 = 0, c0 = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    if (x != i && x != n - i + 1) {
      ++c0;
    } else if (x != i) {
      ++c1;
    } else if (x != n - i + 1) {
      ++c2;
    }
  }
  if ((c1 + c0 <= c2) ^ (c2 + c0 < c1)) {
    cout << ((c1 + c0 <= c2) ? "First\n" : "Second\n");
  } else {
    cout << "Tie\n";
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
