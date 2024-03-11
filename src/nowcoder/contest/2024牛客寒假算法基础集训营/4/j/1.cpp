#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
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

struct Point {
  int x, y;
  void print() {
    cout << x << ' ' << y << endl;
  }
};

Point make_vector(Point p1, Point p2) {
  Point vec;
  vec.x = p2.x - p1.x;
  vec.y = p2.y - p1.y;
  return vec;
}

bool are_parallel(Point vec1, Point vec2) {
  return vec1.x * vec2.y == vec1.y * vec2.x;
}

bool are_collinear(Point p1, Point p2, Point p3) {
  // p1.print();
  // p2.print();
  // p3.print();

  Point vec1 = make_vector(p1, p2);
  Point vec2 = make_vector(p2, p3);
  return are_parallel(vec1, vec2);
}

void solve() {
  int n;
  cin >> n;
  vector<Point> a(n);
  vector<int> b(n);
  for (auto &[x, y] : a) {
    cin >> x >> y;
  }

  if (n == 1) {
    cout << 1 << endl;
    return;
  }

  int ans = 0;
  while (true) {
    bool fl = true;
    for (auto i : b) {
      if (i == 0) {
        fl = false;
        break;
      }
    }
    if (fl) {
      break;
    }

    ++ans;

    vector<int> ma;
    int mac = -1;

    bool first = true;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        vector<int> t = {i, j};
        int tc = 0;
        if (!b[i]) {
          ++tc;
        }
        if (!b[j]) {
          ++tc;
        }
        for (int k = 0; k < n; ++k) {
          if (k == i || k == j) {
            continue;
          }
          if (are_collinear(a[i], a[j], a[k])) {
            t.emplace_back(k);
            if (!b[k]) {
              ++tc;
            }
          }
        }
        // for (auto i : t) {
        //   cout << i << ' ';
        // }
        // cout << endl;
        if (first) {
          first = false;
        } else if (tc == t.size()) {
          continue;
        }
        if (tc > mac) {
          ma = t;
          mac = tc;
        }
      }
    }

    for (auto i : ma) {
      cout << i << ' ';
      b[i] = true;
    }
    cout << endl;
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}
