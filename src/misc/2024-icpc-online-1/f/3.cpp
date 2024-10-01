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
  vector<int> a(n * 10 + 10, inf), l(n * 10 + 10, 0), r(n * 10 + 10, 0),
    val(n * 10 + 10), sy(n * 10 + 10);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
    q;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int tmp = 1, res = a[1], cnt = 0, lt = 1;
  for (int i = 2; i <= n; ++i) {
    if (a[i] == a[i - 1]) {
      tmp++;
    } else {
      cnt++;
      l[cnt] = lt;
      r[cnt] = i - 1;
      for (int j = l[cnt]; j <= r[cnt]; ++j) {
        sy[j] = cnt;
      }
      val[cnt] = a[i - 1];
      q.push({a[i - 1], cnt});
      tmp = 1;
      res = a[i];
      lt = i;
    }
  }
  if (tmp) {
    cnt++;
    l[cnt] = lt;
    r[cnt] = res;
  }
  int ans = 0;
  while (!q.empty()) {
    int zhi = q.top().first;
    int wei = q.top().second;
    q.pop();
    cout << zhi << ' ' << wei << endl;
    if (sy[l[wei]] != wei || sy[r[wei]] != wei) {
      continue;
    }
    int lef = a[l[wei] - 1];
    int rig = a[r[wei] + 1];
    int lb = sy[l[wei] - 1];
    int rb = sy[r[wei] + 1];
    int minn = min(lef, rig);
    ans = ans + (r[wei] - l[wei] + 1) * (minn - zhi);
    cout << "+ans: " << (r[wei] - l[wei] + 1) * (minn - zhi) << ' ' << l[wei]
         << ' ' << r[wei] << ' ' << minn << ' ' << zhi << endl;
    a[l[wei]] = minn;
    a[r[wei]] = minn;
    if (lef == rig) {
      cnt++;
      l[cnt] = l[lb];
      r[cnt] = r[rb];

      a[l[wei]] = minn;
      a[r[wei]] = minn;
      a[l[lb]] = minn;
      a[r[lb]] = minn;
      a[l[rb]] = minn;
      a[r[rb]] = minn;

      sy[l[lb]] = cnt;
      sy[r[lb]] = cnt;
      sy[l[wei]] = cnt;
      sy[r[wei]] = cnt;
      sy[l[rb]] = cnt;
      sy[r[rb]] = cnt;

      q.push({minn, cnt});
    } else {
      if (minn == lef) {
        cnt++;
        l[cnt] = l[lb];
        r[cnt] = r[wei];

        a[l[wei]] = minn;
        a[r[wei]] = minn;
        a[l[lb]] = minn;
        a[r[lb]] = minn;

        sy[l[lb]] = cnt;
        sy[r[lb]] = cnt;
        sy[l[wei]] = cnt;
        sy[r[wei]] = cnt;
        q.push({minn, cnt});
      } else {
        if (minn == rig) {
          cnt++;
          cout << "cnt: " << cnt << endl;
          l[cnt] = l[wei];
          r[cnt] = r[rb];

          a[l[wei]] = minn;
          a[r[wei]] = minn;
          a[l[rb]] = minn;
          a[r[rb]] = minn;

          sy[l[wei]] = cnt;
          sy[r[wei]] = cnt;
          sy[l[rb]] = cnt;
          sy[r[rb]] = cnt;
          q.push({minn, cnt});
        }
      }
    }
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
