#include <cctype>
#include <cstdio>

const int MAXN = 100000;

int n, ans;
int f[200005], a1[200005], a2[200005];

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

void init(int x) {
  for (int i = 1; i <= x; ++i)
    f[i] = i;
}

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void merge(int x, int y) { f[find(x)] = find(y + MAXN); }

int main() {
  n = read();
  init(MAXN << 1);
  for (int i = 1; i <= n; ++i)
    merge(read(), read());
  for (int i = 1; i <= MAXN; ++i)
    ++a1[find(i)];
  for (int i = MAXN + 1; i <= MAXN << 1; ++i)
    ++a2[find(i)];
  for (int i = 1; i <= MAXN << 1; ++i)
    ans += a1[i] * a2[i];
  return print(ans - n), 0;
}