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
  while (!isdigit(ch = getchar()))
    (ch == '-') && (f = 1);
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

int f[300005], n, m, ans;

int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }

void merge(int x, int y) { f[find(x)] = f[y]; }

void init(int x) {
  for (int i = 1; i <= x; ++i)
    f[i] = i;
}

int main() {
  n = read();
  m = read();
  int t1, t2, t3;
  init(n * 3);
  for (int i = 1; i <= m; ++i) {
    t1 = read();
    t2 = read();
    t3 = read();
    if (t1 > n || t2 > n) {
      ++ans;
      continue;
    }
    if (t3 == 1) {
      if (find(t1 + n) == find(t2) || find(t1 + 2 * n) == find(t2)) {
        ++ans;
        continue;
      }
      merge(t1, t2);
      merge(t1 + n, t2 + n);
      merge(t1 + 2 * n, t2 + 2 * n);
    } else if (t2 == 2) {
      if (t1 == t2) {
        ++ans;
        continue;
      }
      if (find(t1) == find(t2) || find(t1 + 1) == find(t2)) {
        ++ans;
        continue;
      }
      merge(t1, t2 + 2 * n);
      merge(t1 + n, t2);
      merge(t1 + 2 * n, t2 + n);
    }
  }
  print(ans);
  return 0;
}