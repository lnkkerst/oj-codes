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
  int n, k;
  cin >> n >> k;
  vector<int> b(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
  if (k == 1) {
    for (int i = 1; i <= n; ++i) {
      if (b[i] != i) {
        cout << "NO" << endl;
        return;
      }
    }
    cout << "YES" << endl;
    return;
  }
  for (int i = 1; i <= n; ++i) {
    if (b[i] == i) {
      cout << "NO" << endl;
      return;
    }
  }
  unordered_map<int, int> bk;
  for (auto i : b) {
    ++bk[i];
  }
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
