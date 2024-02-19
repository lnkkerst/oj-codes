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
  map<int, int> mp = {{100, 0}, {150, 1}, {200, 2}, {29, 0}, {30, 0}, {31, 0},
                      {32, 0},  {34, 1},  {36, 1},  {38, 1}, {40, 1}, {45, 2}};
  int ans = 0;
  for (int i = 0; i < 3; ++i) {
    int x;
    cin >> x;
    ans += mp[x];
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
