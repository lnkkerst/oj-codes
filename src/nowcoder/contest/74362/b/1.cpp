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

bool pd(int x) {
  if (x == 1) {
    return false;
  }
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

void solve() {
  int x;
  cin >> x;
  set<int> b;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      b.insert(x / i);
      b.insert(i);
    }
  }
  int ans = 0;
  for (auto i : b) {
    if (pd(i)) {
      ++ans;
    }
  }
  cout << ans << endl;
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
