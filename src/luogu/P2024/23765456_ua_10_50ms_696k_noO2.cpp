#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define MAXN 66

using namespace std;

int read() {
  int ret;
  char ch;
  bool f = 0;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (f = 1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return f ? -ret : ret;
}

void print(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

int f[300005], n, m, ans = 0;

int find(int x) {
  return x == f[x] ? x : f[x] = find(f[x]);
}

void merge(int x, int y) {
  f[find(x)] = f[y];
}

void init(int x) {
  for (int i = 1; i <= x; ++i) {
    f[i] = i;
  }
}

int main() {
  n = read();
  m = read();
  for (int i = 1; i <= m; ++i) {
    int x = read(), y = read(), z = read();
    if (x > n || y > n) {
      ++ans;
      continue;
    };
    if (z == 1) {
      if (find(x + n) == find(y) || find(x + 2 * n) == find(y)) {
        ++ans;
        continue;
      };
      merge(x, y);
      merge(x + n, y + n);
      merge(x + 2 * n, y + 2 * n);
    } else if (z == 2) {
      if (x == y) {
        ++ans;
        continue;
      };
      if (find(x) == find(y) || find(x + 2 * n) == find(y)) {
        ++ans;
        continue;
      };
      merge(x, y + 2 * n);
      merge(x + n, y);
      merge(x + 2 * n, y + n);
    }
  }
  print(ans);
  return 0;
}
