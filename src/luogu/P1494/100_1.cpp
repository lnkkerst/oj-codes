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
#define endl "\n"

struct Query {
  int l, r;
  int id;
};

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void solve() {
  int n, m;
  cin >> n >> m;
  int bsz = sqrt(n);
  int blk = (n + bsz - 1) / bsz;
  auto get_blk = [&](int x) { return x / bsz; };
  vector<int> a(n);
  vector<int> b(n + 1);
  for (auto &i : a) {
    cin >> i;
  }
  vector<Query> q(m);
  for (int i = 0; i < m; ++i) {
    q[i].id = i;
    cin >> q[i].l >> q[i].r;
    --q[i].l;
    --q[i].r;
  }
  sort(q.begin(), q.end(), [&](const Query &a, const Query &b) {
    int ak = get_blk(a.l), bk = get_blk(b.l);
    if (ak == bk) {
      return a.r < b.r;
    }
    return ak < bk;
  });
  vector<pair<int, int>> ans(m);
  int l = 0, r = -1;
  int sum = 0;
  auto move = [&](int x, int type) {
    if (type == 1) {
      sum += b[x];
      b[x]++;
    } else {
      b[x]--;
      sum -= b[x];
    }
  };
  for (int i = 0; i < m; ++i) {
    if (q[i].l == q[i].r) {
      ans[q[i].id] = {0, 1};
      continue;
    }
    while (l > q[i].l) {
      move(a[--l], 1);
    }
    while (r < q[i].r) {
      move(a[++r], 1);
    }
    while (l < q[i].l) {
      move(a[l++], -1);
    }
    while (r > q[i].r) {
      move(a[r--], -1);
    }
    int x = sum;
    int y = (r - l + 1) * (r - l) / 2;
    if (x != 0) {
      int g = gcd(x, y);
      x /= g;
      y /= g;
    } else {
      y = 1;
    }
    ans[q[i].id] = {x, y};
  }
  for (auto [x, y] : ans) {
    cout << x << '/' << y << endl;
  }
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
