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
  // int maxid = 0;
  // map<int, int> id;
  // map<int, int> mp;
  // for (auto x : s) {
  //   id[x] = ++maxid;
  //   mp[maxid] = x;
  // }

  // for (int i = 1; i <= n; ++i) {
  //   a[i] = id[a[i]];
  // }

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
  //   for (int j = i; j <= n; ++j) {
  //     cout << b[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  vector<vector<int>> c(n + 10, vector<int>(n + 10));
  auto get_mid = [&](vector<int> a) {
    sort(a.begin(), a.end());
    return a[(a.size() - 1) / 2];
  };
  for (int i = 1; i <= n; ++i) {

    for (int j = i; j <= n; ++j) {
      vector<int> tmp;
      for (int k = i; k <= j; ++k) {
        for (int l = k; l <= j; ++l) {
          tmp.emplace_back(b[k][l]);
        }
      }
      c[i][j] = get_mid(tmp);
    }
  }
  vector<int> ca;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      ca.emplace_back(c[i][j]);
      // cout << c[i][j] << ' ';
    }
    // cout << endl;
  }
  cout << get_mid(ca);
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
