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
  vector<int> ans;
  ans.emplace_back(x);
  int tx = x;
  int base = 1;
  while (tx != 1) {
    if (tx & 1) {
      x -= base;
      ans.emplace_back(x);
    }
    tx >>= 1;
    base *= 2;
  }
  while (x != 1) {
    x >>= 1;
    ans.emplace_back(x);
  }
  cout << ans.size() << endl;
  for (auto i : ans) {
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
