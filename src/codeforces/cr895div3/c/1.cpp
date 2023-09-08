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

void solve() {
  int l, r;
  cin >> l >> r;
  int mid = (l + r) / 2;
  if (l != r || l % 2 == 0) {
    int mid = r;
    if (mid % 2 != 0) {
      --mid;
    }
    int a = 2;
    int b = mid - a;
    if (b < 2) {
      cout << -1 << endl;
    } else {
      cout << a << ' ' << b << endl;
    }
    return;
  }
  for (int i = 2; i * i <= l; ++i) {
    if (l % i == 0) {
      cout << i << ' ' << l - i << endl;
      return;
    }
  }
  cout << -1 << endl;
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
