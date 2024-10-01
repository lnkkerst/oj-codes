#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

void solve() {
  int n;
  cin >> n;
  set<int> a;
  for (int i = 1; i <= n; ++i) {
    a.insert(i);
  }
  vector<int> ans;
  while (!a.empty()) {
    auto it = a.begin();
    for (int x = *it; x <= n; x *= 2) {
      auto it = a.find(x);
      if (it == a.end()) {
        continue;
      } else {
        ans.emplace_back(*it);
        a.erase(it);
      }
    }
  }
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << endl;
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
