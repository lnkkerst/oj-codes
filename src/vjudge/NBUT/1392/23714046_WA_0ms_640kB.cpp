#include <cctype>
#include <cstdio>

int n, m, ans = 0;
int fa[50010];

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
  for (int i = 1; i <= n; ++i)
    fa[i] = i;
}

int find(int x) { return x == fa[x] ? x : find(fa[x]); }

void merge(int u, int v) { fa[find(u)] = find(v); }

int main() {
  n = read(), m = read();
  init(n);
  while (m--)
    merge(read(), read());
  for (int i = 1; i <= n; ++i)
    if (fa[i] == i)
      ++ans;
  return print(ans), 0;
}