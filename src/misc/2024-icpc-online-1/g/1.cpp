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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 10);
  vector<vector<int>> b(n + 10, vector<int>(n + 10));
  set<int> s;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    s.insert(a[i]);
  }
  int maxid = 0;
  map<int, int> id;
  map<int, int> mp;
  for (auto x : s) {
    id[x] = ++maxid;
    mp[maxid] = x;
  }

  for (int i = 1; i <= n; ++i) {
    a[i] = id[a[i]];
  }

  for (int i = 1; i <= n; ++i) {
    priority_queue<int> lq;
    priority_queue<int, vector<int>, greater<int>> rq;

    auto adjust = [&](int sz) {
      while (lq.size() < sz && !rq.empty()) {
        lq.push(rq.top());
        rq.pop();
      }
      while (lq.size() > sz) {
        rq.push(lq.top());
        lq.pop();
      }
    };

    auto push = [&](int x) {
      if (lq.empty() || x < lq.top()) {
        lq.push(x);
      } else {
        rq.push(x);
      }
      int mid = (lq.size() + rq.size() + 1) / 2;
      adjust(mid);
    };

    auto get_mid = [&]() {
      return lq.top();
    };

    for (int j = i; j <= n; ++j) {
      push(a[j]);
      b[i][j] = get_mid();
    }
  }

  // for (int i = 1; i <= n; ++i) {
  //   for (int j = 1; j <= n; ++j) {
  //     cout << setw(4) << b[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  // reverse(b.begin(), b.end());

  int l = 1, r = maxid;
  while (l < r) {
    int mid = (l + r + 1) / 2;

    vector<vector<int>> p(n + 10, vector<int>(n + 10));

    for (int i = n; i >= 1; --i) {
      for (int j = 1; j <= n; ++j) {
        if (b[i][j] >= mid) {
          p[i][j] = 1;
        } else {
          p[i][j] = 0;
        }
      }
    }

    for (int i = n; i >= 1; --i) {
      for (int j = 1; j <= n; ++j) {
        p[i][j] += p[i][j - 1] + p[i + 1][j] - p[i + 1][j - 1];
      }
    }

    int cnt = 0;

    for (int i = 1; i <= n; ++i) {
      for (int j = i; j <= n; ++j) {
        int h = j - i + 1;
        int w = h;
        int area = (h * (w + 1)) / 2;
        // cout << "hw: " << h << ' ' << w << ' ' << area << endl;
        if (area - p[i][j] + 1 <= (area + 1) / 2) {
          ++cnt;
          // cout << p[i][j] << ' ' << i << ' ' << j << endl;
        }
      }
    }
    // cout << "cnt: " << cnt << endl;
    int N = (n * n + n) / 2;
    if (N - cnt + 1 <= (N + 1) / 2) {
      l = mid;
    } else {
      r = mid - 1;
    }
    // cout << mp[mid] << endl;
  }
  if (mp.find(l) == mp.end()) {
    throw 114514;
  }
  cout << mp[l] << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
