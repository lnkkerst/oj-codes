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
  int n, m, d;
  cin >> n >> m >> d;
  vector<int> a(m);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  int ans1 = m;
  if (a.front() != 1) {
    a.insert(a.begin(), 1);
    ++ans1;
  }
  for (int i = 1; i < a.size(); ++i) {
    ans1 += (a[i] - a[i - 1] - 1) / d;
  }
  ans1 += (n - a.back()) / d;
  int ans = 0;
  for (int i = 1; i < a.size() - 1; ++i) {
    int ne = (a[i + 1] - a[i - 1] - 1) / d;
    int ol = (a[i] - a[i - 1] - 1) / d + (a[i + 1] - a[i] - 1) / d + 1;
    if (ne < ol) {
      ++ans;
    }
  }
  int ne = (n - a[a.size() - 2]) / d;
  int ol = (n - a[a.size() - 1]) / d
           + (a[a.size() - 1] - a[a.size() - 2] - 1) / d + 1;
  if (ne < ol) {
    ++ans;
  }
  if (ans == 0) {
    cout << ans1 << ' ' << m << endl;
  } else {
    cout << ans1 - 1 << ' ' << ans << endl;
  }
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
