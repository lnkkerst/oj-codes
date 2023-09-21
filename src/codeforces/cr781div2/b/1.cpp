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
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> b;
  for (auto &i : a) {
    cin >> i;
    ++b[i];
  }
  int mx = 0;
  for (auto i : b) {
    mx = max(mx, i.second);
  }
  int ans = 0;
  while (mx < n) {
    int t = min(n - mx, mx);
    ans += t + 1;
    mx += t;
  }
  cout << ans << endl;
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
