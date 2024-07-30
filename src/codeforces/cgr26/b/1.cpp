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

void solve() {
  int x;
  cin >> x;
  int last = 0;
  while (x >= 10) {
    int cur = x % 10;
    cur -= last;
    cur += 10;
    if (cur > 18 || cur < 10) {
      cout << "NO" << endl;
      return;
    }
    last = 1;
    x /= 10;
  }
  if (x != last) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
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
