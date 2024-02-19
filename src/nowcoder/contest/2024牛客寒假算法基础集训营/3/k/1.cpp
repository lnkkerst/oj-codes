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
  int a, b;
  cin >> a >> b;
  int n = a + b;
  if (a % 2 == 0 || b % 2 != 0) {
    cout << "No" << endl;
    return;
  }
  // if ((a - 1) > b * 2 || b > (a - 1) * 2) {
  //   cout << "No" << endl;
  //   return;
  // }
  int pre = 1, cur = 2, curh = 2;
  map<int, int> mp;
  mp[1] = 1;
  a -= 1;
  while (true) {
    int dif;
    if (!a && !b) {
      break;
    }
    if (cur == 2) {
      dif = min(pre * 2, b);
      b -= dif;
      if (a == 0 && b != 0) {
        cout << "No" << endl;
        return;
      }
    } else {
      dif = min(pre * 2, a);
      a -= dif;
      if (b == 0 && a != 0) {
        cout << "No" << endl;
        return;
      }
    }
    mp[curh] = dif;
    if (cur == 2) {
      cur = 1;
    } else {
      cur = 2;
    }
    ++curh;
    pre = dif;
  }
  vector<int> l(n + 1, -1), r(n + 1, -1);
  int tot = 0;
  map<int, map<int, int>> e;
  int id = 0;
  for (auto [level, cnt] : mp) {
    for (int i = 1; i <= cnt; ++i) {
      e[level][i] = ++id;
      if (i & 1) {
        l[e[level - 1][(i + 1) / 2]] = id;
      } else {
        r[e[level - 1][i / 2]] = id;
      }
    }
  }
  cout << "Yes" << endl;
  for (int i = 1; i <= n; ++i) {
    cout << l[i] << ' ' << r[i] << endl;
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
