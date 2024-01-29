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
  int n, p;
  cin >> n >> p;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  if (a[p] != 9) {
    cout << "0 0" << endl;
    return;
  }
  deque<int> l, r;
  int cl = 1, cr = 1;
  for (int i = 1; i <= p - 1; ++i) {
    l.emplace_back(a[i]);
  }
  for (int i = n; i >= p + 1; --i) {
    r.emplace_back(a[i]);
  }
  while (true) {
    bool fl1 = true;
    bool fl2 = true;
    if (cl && !l.empty()) {
      int lt = l.back();
      l.pop_back();
      ++lt;
      --cl;
      if (lt == 10) {
        ++cl;
        ++cr;
      } else {
        l.emplace_back(lt);
      }
      fl1 = false;
    }
    if (cr && !r.empty()) {
      fl2 = false;
      int rt = r.back();
      r.pop_back();
      ++rt;
      --cr;
      if (rt == 10) {
        ++cl;
        ++cr;
      } else {
        r.emplace_back(rt);
      }
    }
    if (fl1 && fl2) {
      break;
    }
  }
  cout << cl << ' ' << cr << endl;
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
