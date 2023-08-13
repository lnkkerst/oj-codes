#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  auto check = [&](int tar) -> bool {
    for (int i = 0; i < a.size(); ++i) {
      int rest = k;
      int ctar = tar;
      for (int j = i; j < a.size(); ++j) {
        if (a[j] >= ctar) {
          return true;
        }
        if (rest < ctar - a[j]) {
          break;
        }
        rest -= ctar - a[j];
        --ctar;
      }
    }
    return false;
  };
  int l = 1, r = 2e8;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
