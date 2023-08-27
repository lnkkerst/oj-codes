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
  int n, x, y;
  cin >> x >> y >> n;
  vector<int> a(n);
  int div = 1;
  a[n - 1] = y;
  for (int i = n - 2; i >= 1; --i) {
    a[i] = a[i + 1] - div;
    ++div;
  }
  a[0] = x;
  if (a[1] - a[0] < div) {
    cout << -1 << endl;
    return;
  }
  for (auto i : a) {
    cout << i << ' ';
  }
  cout << endl;
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
