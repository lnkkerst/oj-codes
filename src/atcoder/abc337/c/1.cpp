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
  vector<int> a(n + 1);
  vector<int> r(n + 1);
  int f = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] == -1) {
      f = i;
    } else {
      r[a[i]] = i;
    }
  }
  int cur = f;
  vector<int> ans{cur};
  while (r[cur]) {
    cur = r[cur];
    ans.emplace_back(cur);
  }
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << endl;
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
