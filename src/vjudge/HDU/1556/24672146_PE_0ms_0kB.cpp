#include <cstring>
#include <iostream>
using namespace std;

int a[100010], n, m;

int lowbit(int x) {
  return x & -x;
}

void add(int x, int v) {
  while (x <= n) {
    a[x] += v, x += lowbit(x);
  }
}

int query(int x) {
  int ret = 0;
  while (x) {
    ret += a[x], x -= lowbit(x);
  }
  return ret;
}

int main() {
  while (233) {
    cin >> n;
    if (!n) {
      return 0;
    }
    for (int i = 1; i <= n; ++i) {
      int l, r;
      cin >> l >> r;
      add(l, 1);
      add(r + 1, -1);
    }
    for (int i = 1; i <= n; ++i) {
      cout << query(i) << ' ';
    }
    puts("");
    memset(a, 0, sizeof(a));
  }
}
