#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void solve() {
  int n = 20;
  vector<int> a(n);
  vector<int> aa;
  for (int i = 0; i < n; ++i) {
    a[i] = i + 1;
  }
  int ans = 0;
  do {
    int t = 0;
    int ma = 0;
    for (int i = 0; i < n; ++i) {
      t += (i + 1) * a[i];
      ma = max(ma, (i + 1) * a[i]);
    }
    t -= ma;
    if (t > ans) {
      ans = t;
      aa = a;
    }
  } while (next_permutation(a.begin(), a.end()));
  cout << ans << endl;
  for (auto i : aa) {
    cout << i << ' ';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
