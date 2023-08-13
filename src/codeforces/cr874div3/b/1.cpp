#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    a[i].second = i;
  }
  auto b = a;
  for (auto &i : a) {
    cin >> i.first;
  }
  for (auto &i : b) {
    cin >> i.first;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    ans[a[i].second] = b[i].first;
  }
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
