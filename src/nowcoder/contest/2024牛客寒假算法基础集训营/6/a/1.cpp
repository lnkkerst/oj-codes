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

bool pd(int x) {
  if (x == 1) {
    return false;
  }
  if (x == 2) {
    return true;
  }
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

void solve() {
  int l, r;
  cin >> l >> r;
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= r; ++j) {
      for (int k = 1; k <= r; ++k) {
        if (i * j * k >= l && i * j * k <= r && pd(i) && pd(j) && pd(k)
            && i != j && j != k && i != k) {
          cout << i * j * k << endl;
          return;
        }
      }
    }
  }
  cout << -1 << endl;
  return;
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
