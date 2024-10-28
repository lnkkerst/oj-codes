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
  using pii = pair<int, int>;
  vector<pii> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  auto calc = [&](vector<int> a) {
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (a[i] > a[j]) {
          ++ans;
        }
      }
    }
    return ans;
  };
  sort(a.begin() + 1, a.begin() + n + 1, [](pii a, pii b) {
    if (a.first > a.second) {
      swap(a.first, a.second);
    }
    if (b.first > b.second) {
      swap(b.first, b.second);
    }
    return a < b;
  });
  for (int i = 1; i <= n; ++i) {
    cout << a[i].first << ' ' << a[i].second << ' ';
  }
  cout << endl;
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
