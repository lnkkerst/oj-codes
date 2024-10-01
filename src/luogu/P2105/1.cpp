#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
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
  int n, k;
  cin >> n >> k;
  vector<vector<vector<int>>> dp(
    n + 1, vector<vector<int>>((1 << n) + 1, vector<int>(k + 1)));
  auto check = [&](int x, int y) {
    return !(x & y || x & (y << 1) || (x << 1) & y);
  };
  for (int i = 1; i <= n; ++i) {}
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
