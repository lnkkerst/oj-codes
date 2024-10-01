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

int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> b;
  int ma = 0;
  for (auto &i : a) {
    cin >> i;
    ++b[i];
    ma = max(ma, i);
  }
  sort(a.begin(), a.end());
  vector<vector<int>> d(ma + 1);
  for (int i = 1; i <= ma; ++i) {
    for (int j = i; j <= ma; j += i) {
      for (int k = 0; k < b[j]; ++k) {
        d[i].emplace_back(j);
      }
    }
  }
  int ans = 0;
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
