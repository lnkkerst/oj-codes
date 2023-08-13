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

void solve() {
  int n;
  cin >> n;
  unordered_map<int, int> b;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    ++b[x];
    cnt += x - 1;
  }
  if (n == 1) {
    cout << "NO" << endl;
    return;
  }
  if (cnt < b[1]) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
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
