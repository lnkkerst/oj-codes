#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define int long long

void solve() {
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> a(n);
  vector<int> b(k + 1);
  vector<int> ans(n);
  for (auto &i : a) {
    cin >> i;
    ++b[i];
  }
  auto calc = [&](vector<int> a, int m) {
    int n = a.size();
    vector<int> ans(n);
    set<int> q;
    int cur = 0;
    while (m--) {
      if (q.find(a[cur]) != q.end()) {
        q.erase(a[cur]);
        ++ans[cur];
      } else {
        q.insert(a[cur]);
      }
      ++cur;
      cur %= n;
    }
    return ans;
  };
  auto r2 = calc(a, n * 2);
  // for (auto i : r2) {
  //   cout << i << ' ';
  // }
  // cout << endl;
  int round = m / n;
  m %= n;
  if (round & 1) {
    --round;
    m += n;
  }
  for (int i = 0; i < n; ++i) {
    ans[i] += r2[i] * (round / 2);
  }
  auto rs = calc(a, m);
  for (int i = 0; i < n; ++i) {
    ans[i] += rs[i];
  }
  for (int i = 0; i < n; ++i) {
    if (i != 0) {
      cout << ' ';
    }
    cout << ans[i];
  }
  cout << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
