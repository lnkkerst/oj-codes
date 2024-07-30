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
  int n;
  cin >> n;
  set<int> s;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    s.insert(x);
  }
  if (s.size() == 1) {
    cout << 0 << endl;
    return;
  }
  set<int> a;
  int last = -1;
  for (auto x : s) {
    if (last == -1) {
      last = x;
      continue;
    }
    a.insert(x - last);
    last = x;
  }
  int g = *a.begin();
  for (auto x : a) {
    g = __gcd(g, x);
  }
  cout << g << endl;
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
