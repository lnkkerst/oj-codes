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
  vector<int> a(n + 1);
  vector<int> p(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[a[i]] = i;
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == i || a[a[i]] == i) {
      continue;
    }
    ++ans;
    int pi = p[i];
    int aai = a[a[i]];
    swap(a[p[i]], a[a[i]]);
    p[i] = a[i];
    p[aai] = pi;
  }
  cout << ans << endl;
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
