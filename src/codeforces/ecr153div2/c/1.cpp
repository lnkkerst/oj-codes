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
  for (auto &i : a) {
    cin >> i;
  }
  int mi = a[0], ma = 0, mi2 = 1e8;
  set<int> q;
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] < mi) {
      mi = a[i];
    } else {
      if (q.empty() || *q.begin() > a[i]) {
        ++ans;
      }
      q.insert(a[i]);
    }
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
