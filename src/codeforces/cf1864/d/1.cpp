#pragma GCC optimize(2)
#include <algorithm>
#include <array>
#include <cstdio>
#include <functional>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

constexpr int MAXN = 4010 * 2;
struct Tree {
  int a[MAXN], tree[MAXN];
  int n;
  int query(int pos) {
    int res = 0;
    while (pos > 0) {
      res += tree[pos];
      pos -= pos & -pos;
    }
    return res;
  }
  void add(int pos, int val) {
    while (pos <= this->n) {
      tree[pos] += val;
      pos += pos & -pos;
    }
  }
  void init() {
    for (int i = 0; i <= this->n; ++i) {
      a[i] = tree[i] = 0;
    }
  }
  void radd(int l, int r, int val) {
    add(l, val);
    add(r + 1, -val);
  }
} t0, t1;

int get0(int x, int y, int n) {
  return x + y + 1;
}
int get1(int x, int y, int n) {
  return (x) + (n - y - 1) + 1;
}

char s[MAXN];

void solve() {
  int n;
  scanf("%d", &n);
  t0.n = n * 2 - 1;
  t1.n = n * 2 - 1;
  t0.init();
  t1.init();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    vector<int> p;
    for (int j = 0; j < n; ++j) {
      if ((t0.query(get0(i, j, n)) + t1.query(get1(i, j, n)) + s[j] - '0')
          & 1) {
        ++ans;
        p.push_back(j);
      }
    }
    for (auto j : p) {
      t0.radd(get0(i, j, n), get0(n - 1, n - 1, n), 1);
      if (j != n - 1) {
        t1.radd(get1(i, n - 1, n), get1(i, j + 1, n), 1);
      }
    }
  }
  printf("%d\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
