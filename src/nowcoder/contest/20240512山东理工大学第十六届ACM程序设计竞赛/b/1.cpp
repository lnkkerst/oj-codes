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
  map<string, int> b;
  for (int i = 1; i <= n; ++i) {
    string s;
    int x;
    cin >> s >> x;
    b[s] = x;
  }

  int w;
  cin >> w;
  while (w--) {
    string s;
    cin >> s;
    --b[s];
  }
  int ans = 0;
  for (auto [k, v] : b) {
    ans += v == 0;
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
