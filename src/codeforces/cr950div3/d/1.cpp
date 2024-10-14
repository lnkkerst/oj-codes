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
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  auto get_d = [&](const vector<int> &a) {
    int n = a.size();
    vector<int> d(n - 1);
    for (int i = 0; i < n - 1; ++i) {
      d[i] = gcd(a[i], a[i + 1]);
    }
    return d;
  };
  auto check = [&](const vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
      if (a[i] > a[i + 1]) {
        return false;
      }
    }
    return true;
  };
  auto delete_and_check = [&](vector<int> a, int pos) {
    // cout << pos << endl;
    a.erase(a.begin() + pos);
    return check(get_d(a));
  };
  auto d = get_d(a);
  // for (auto i : d) {
  //   cout << i << ' ';
  // }
  // cout << endl;
  int cnt = 0;
  if (check(d)) {
    cout << "YES" << endl;
    return;
  }
  for (int i = 0; i < d.size() - 1; ++i) {
    if (d[i] > d[i + 1]) {
      ++cnt;
      if (cnt >= 5) {
        cout << "NO" << endl;
        return;
      }
      for (int j = max(0, i - 3); j < min((int)a.size(), i + 3); ++j) {
        if (delete_and_check(a, j)) {
          cout << "YES" << endl;
          return;
        }
      }
    }
  }
  cout << "NO" << endl;
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
