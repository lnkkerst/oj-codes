#include <algorithm>
#include <cctype>
#include <cstdio>

struct Node {
  int x, y;
} e[50010];

int f[50010];
int n, a[50010], b[50010];

bool cmp(Node a, Node b) { return a.x < b.x; }

inline int lowbit(int x) { return x & -x; }

int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (f = -1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

void print(int x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

void add(int x) {
  for (int i = x; i; i -= lowbit(i))
    ++f[i];
}

int query(int x) {
  int ret = 0;
  for (int i = x; i <= 50009; i += lowbit(i))
    ret += f[i];
  return ret;
}

int main() {
  n = read();
  for (int i = 1; i <= n; ++i)
    e[i].x = read(), e[i].y = read(), a[i] = e[i].y;
  std::sort(a + 1, a + n + 1);
  std::sort(e + 1, e + n + 1, cmp);
  int l = 1, r = 0, ans = 0;
  e[0].x = 1;
  for (int i = 1; i <= n; ++i) {
    if (e[i].x == e[i - 1].x)
      ++r;
    else if (e[i].x != e[i - 1].x) {
      for (int j = l; j <= r; ++j)
        add(b[j]);
      l = r = i;
    }
    b[i] = std::lower_bound(a + 1, a + n + 1, e[i].y) - a;
    ans += query(b[i] + 1);
  }
  return print(ans), 0;
}