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
  int n, q;
  cin >> n >> q;
  set<int> s;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  auto insert = [&](const vector<int> &a) {
    int res = 1;
    for (auto i : a) {
      res *= i;
      if (res > 1e9 || res < -1e9) {
        return false;
      }
    }
    s.insert(res);
    return true;
  };
  auto inc = [&](vector<int> &a) {
    for (auto &i : a) {
      ++i;
    }
  };
  auto dec = [&](vector<int> &a) {
    for (auto &i : a) {
      --i;
    }
  };
  auto na = a;
  insert(na);
  for (int i = 1; i <= 1000; ++i) {
    inc(na);
    insert(na);
  }
  na = a;
  for (int i = 1; i <= 1000; ++i) {
    dec(na);
    insert(na);
  }
  while (q--) {
    int x;
    cin >> x;
    if (s.find(x) != s.end()) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
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
