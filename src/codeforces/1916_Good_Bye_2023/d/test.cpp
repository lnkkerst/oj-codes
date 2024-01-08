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
  int n = 1e6;
  map<string, vector<int>> b;
  auto ts = [&](int x) {
    string s = to_string(x);
    sort(s.begin(), s.end());
    return s;
  };
  int ma = 0;
  vector<int> mav;
  for (int i = 1; i <= n; ++i) {
    auto x = i * i;
    b[ts(x)].emplace_back(x);
  }
  for (auto &[k, v] : b) {
    if (v.size() > ma) {
      ma = v.size();
      mav = v;
    }
    ma = max(ma, (int)v.size());
    if (k.length() != 11) {
      continue;
    }
    if (v.size() < k.length()) {
      continue;
    }
    cout << "k" << k << endl;
    for (auto i : v) {
      cout << i << ' ';
    }
    cout << endl;
  }
  cout << ma << endl;
  for (auto i : mav) {
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
