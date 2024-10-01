#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
#define int long long
constexpr int inf = 1e18;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 100), l(n + 100), r(n + 100);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
    q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    l[i] = i - 1;
    r[i] = i + 1;
    q.push({a[i], i});
  }
  int ans = 0;
  a[0] = inf;
  a[n + 1] = inf;
  while (!q.empty()) {
    int val = q.top().first;
    int wei = q.top().second;
    cout << val << ' ' << wei << endl;
    q.pop();
    int cnt = min(a[l[wei]], a[r[wei]]);
    if (cnt == inf) {
      break;
    }
    if (cnt == val) {
      if (a[l[wei]] == cnt) {
        r[l[wei]] = r[wei];
        l[r[wei]] = l[wei];
      }
      if (a[r[wei]] == cnt) {
        l[r[wei]] = l[wei];
        r[l[wei]] = r[wei];
      }
    } else {
      if (a[l[wei]] == cnt) {
        ans = ans + (a[l[wei]] - a[wei]) * (wei - l[wei]);
        r[l[wei]] = r[wei];
        l[r[wei]] = l[wei];
        a[wei] = a[l[wei]];
      }
      if (a[r[wei]] == cnt) {
        ans = ans + (a[r[wei]] - a[wei]) * (r[wei] - wei);
        l[r[wei]] = l[wei];
        r[l[wei]] = r[wei];
        a[wei] = a[r[wei]];
      }
    }
    cout << ans << endl;
  }
  cout << ans << endl;
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
}
