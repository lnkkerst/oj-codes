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
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  auto calc = [&](int c0, int c1) {
    int de = c1 / 3;
    int re = c1 % 3;
    if (c1 == 0) {
      ++de;
    }
    return de;
  };
  int tot = 0, c0 = 0, c1 = 0;
  for (int i = 0; i < n; ++i) {
    if (i & 1) {
      ++c1;
    } else {
      ++c0;
    }
    tot += i;
    cout << tot - calc(c0, c1) << ' ';
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
