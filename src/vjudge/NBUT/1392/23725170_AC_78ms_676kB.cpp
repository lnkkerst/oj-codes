#include <cctype>
#include <cstdio>
#include <iostream>
using namespace std;
int fa[50010], n, m, v, u, ans;
inline int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (f = -1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

inline void print(int x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}
void init(int x) {
  for (int i = 1; i <= x; ++i)
    fa[i] = i;
}
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(int u, int v) { fa[find(u)] = find(v); }
void work() {
  init(n), ans = 0;
  for (int i = 1; i <= m; ++i)
    merge(read(), read());
  for (int i = 1; i <= n; ++i)
    if (fa[i] == i)
      ++ans;
  print(ans), putchar('\n');
}
int main() {
  while (cin >> n >> m)
    work();
  return 0;
}