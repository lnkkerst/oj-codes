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
  int x;
  cin >> x;
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      cout << i << x / i;
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  // cin >> t;
  t = 1;
  while (t--) {
    solve();
  }
}
