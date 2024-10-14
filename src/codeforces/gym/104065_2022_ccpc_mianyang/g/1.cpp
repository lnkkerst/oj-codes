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

int sgn(int x) {
  if (x > 0) {
    return 1;
  }
  if (x < 0) {
    return -1;
  }
  return 0;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int ans = 0;
  while (a.size() > 1) {
    vector<int> del(a.size());
    for (int i = 0; i < a.size(); ++i) {
      bool fl = false;
      if (i > 0 && a[i] < a[i - 1]) {
        fl = true;
      }

      if (i < a.size() - 1 && a[i] < a[i + 1]) {
        fl = true;
      }
      if (fl) {
        del[i] = true;
      }
    }
    vector<int> na;
    for (int i = 0; i < a.size(); ++i) {
      if (!del[i]) {
        na.emplace_back(a[i]);
      }
    }
    a = na;
    ++ans;
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
