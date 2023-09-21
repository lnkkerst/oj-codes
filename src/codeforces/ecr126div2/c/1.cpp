#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  int ma = *max_element(a.begin(), a.end());
  auto calc = [&](int x) {
    int l = 0, r = 1e18;
    int ca = 0, cj = 0;
    for (auto i : a) {
      ca += (x - i);
      cj += (x - i) & 1;
    }
    while (l < r) {
      int mid = (l + r) / 2;
      if ([&]() {
            int tj = (mid + 1) / 2;
            if (tj < cj) {
              return false;
            }
            int ta = tj * 1 + (mid - tj) * 2;
            if (ta < ca) {
              return false;
            }
            return true;
          }()) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  };
  cout << min(calc(ma), calc(ma + 1)) << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
