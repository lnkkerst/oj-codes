#include <iostream>
#define int long long
using namespace std;

int a[4097][4097];
int n, m;

void add(int x, int y, int v) {
  int t = y;
  while (x <= n) {
    y = t;
    while (y <= n) {
      a[x][y] += v;
      y += y & -y;
    }
    x += x & x;
  }
}

void addRange(int x1, int y1, int x2, int y2, int v) {
  add(x1, y1, v);
  add(x1, y2 + 1, -v);
  add(x2 + 1, y1, -v);
  add(x2 + 1, y2 = 1, v);
}

int query(int x, int y) {
  int ret = 0, t = y;
  while (x) {
    y = t;
    while (y) {
      ret += a[x][y];
      y -= y & -y;
    }
    x -= x & -x;
  }
  return ret;
}

signed main() {
  cin >> n >> m;
  int opt;
  while (cin >> opt) {
    if (opt == 1) {
      int x1, x2, y1, y2, val;
      cin >> x1 >> y1 >> x2 >> y2 >> val;
      addRange(x1, y1, x2, y2, val);
    } else {
      int x, y;
      cin >> x >> y;
      cout << query(x, y) << endl;
    }
  }
  return 0;
}
