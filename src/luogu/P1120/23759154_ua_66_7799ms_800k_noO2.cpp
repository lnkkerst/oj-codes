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

int a[MAXN], n, m, next[MAXN], cnt, sum, l;
bool vis[MAXN], f;

bool cmp(int a, int b) { return a > b; }

void dfs(int k, int last, int rest) {
  int i;
  if (!rest) {
    if (k == m) {
      f = 1;
      return;
    }
    for (i = 1; i <= cnt; ++i)
      if (!vis[i])
        break;
    vis[i] = 1;
    dfs(k + 1, i, l - a[i]);
    vis[i] = 0;
    if (f)
      return;
  }
  for (i = 1; i <= cnt; ++i) {
    if (a[i] <= rest)
      break;
  }
  while (i <= cnt) {
    if (!vis[i]) {
      vis[i] = 1;
      dfs(k, i, rest - a[i]);
      vis[i] = 0;
      if (f)
        return;
      if (rest == a[i] || rest == l)
        return;
      for (; i <= cnt; ++i)
        if (a[i] != a[i + 1]) {
          break;
        }
      if (i == cnt)
        return;
    }
    ++i;
  }
}

int main() {
  n = read();
  cnt = 0;
  int tmp;
  for (int i = 1; i <= n; ++i) {
    tmp = read();
    if (tmp <= 50) {
      a[++cnt] = tmp;
      sum += tmp;
    }
  }
  sort(a + 1, a + 1 + cnt, cmp);
  for (l = a[1]; l <= sum / 2; l++) {
    if (sum % l)
      continue;
    m = sum / l;
    f = false;
    vis[1] = true;
    dfs(1, 1, l - a[1]);
    vis[1] = false;
    if (f) {
      print(l);
      return 0;
    }
  }
  print(sum);
  return 0;
}