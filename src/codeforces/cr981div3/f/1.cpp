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

constexpr int MOD = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  n %= MOD;
  if (k == 1) {
    cout << n << endl;
    return;
  }
  vector<int> f = {0, 1};
  while (true) {
    f.emplace_back((*f.rbegin() + *next(f.rbegin())) % k);
    if (f.back() == 0) {
      break;
    }
  }
  cout << n * (f.size() - 1) % MOD << endl;
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
