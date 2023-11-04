#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define int long long

void solve() {
  map<int, int> mp;
  int sum1 = 0, sum2 = 0, cnt = 0;
  int n, m;
  cin >> n >> m;
  int dif = n - m, poi;
  vector<int> a(n + 10), b(m + 10), ans(n + 10);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
  }
  for (int i = dif + 1; i <= n; ++i) {
    sum1 += a[i];
  }
  for (int i = 1; i <= m; ++i) {
    sum2 += b[i];
  }
  int pd = 0;
  poi = 2;
  for (int i = 1; i <= dif - sum2 + sum1; ++i) {
    ++cnt;
    if (cnt > dif) {
      cout << -1 << endl;
      return;
    }
    ans[cnt] = a[i];
    if (a[i] == a[i + 1]) {
      a[mp[a[i]]]++;
    }
    if (mp.find(a[mp[a[i]]]) == mp.end()) {
      mp[a[mp[a[i]]]] = mp[a[i]];
    }
    if (mp[a[i]] >= dif + 1) {
      ++sum1;
    }
    mp[a[i]]--;
    if (mp[a[i]] <= i) {
      mp.erase(a[i]);
    }
    if (sum2 - sum1 < 0) {
      cout << -1 << endl;
      return;
    }
  }
  for (int i = dif + 1; i <= n; ++i) {
    if (b[i - dif] < a[i]) {
      pd = 1;
      break;
    }
    int qwq = a[i];
    for (int j = 1; j <= b[i - dif] - qwq; ++j) {
      ++cnt;
      if (cnt > dif) {
        cout << -1 << endl;
        return;
      }
      ans[cnt] = a[i];
      ++a[i];
    }
  }
  if (sum2 - sum1 >= 0 && sum2 - sum1 <= dif && pd == 0) {
    cout << dif << endl;
    for (int i = 1; i <= cnt; ++i) {
      cout << ans[i] << ' ';
    }
    cout << endl;
  } else {
    cout << -1 << endl;
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
