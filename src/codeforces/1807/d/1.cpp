#pragma GCC optimize(3)
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
  int n, k;
  cin >> n;
  vector<int> c(n);
  for (auto &i : c) {
    cin >> i;
  }
  for (int i = n - 2; i >= 0; --i) {
    c[i] = min(c[i], c[i + 1]);
  }
  cin >> k;
  vector<int> a(n);
  int cur = 1e9;
  for (int i = 0; i < n; ++i) {
    int x = c[i] - (i == 0 ? 0 : c[i - 1]);
    int buy = x == 0 ? cur : min(cur, k / x);
    a[i] = buy;
    cur = buy;
    k -= x * buy;
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
