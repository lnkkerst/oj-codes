#include <cctype>
#include <cstdio>

const int MAXN = 100010;
int fa[MAXN], tr[MAXN];
int n, m, t, cnt;

int read() {
  int ret, fl = 1;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (fl = -1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * fl;
}

void print(int x) {
  if (x < 0) {
    putchar('-'), x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

int find(int x) {
  return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
  fa[find(x)] = find(y);
}

void sepa(int x) {
  tr[x] = ++cnt + n - 1;
  fa[tr[x]] = tr[x];
}

int main() {
  while (233) {
    n = read(), m = read();
    if (!n || !m) {
      return 0;
    }
    for (int i = 0; i < n; ++i) {
      fa[i] = tr[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
      char opt = getchar();
      while (opt != 'M' && opt != 'S') {
        opt = getchar();
      }
      if (opt == 'M') {
        merge(tr[read()], tr[read()]);
      } else {
        sepa(read());
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += fa[tr[i]] == tr[i];
    }
    printf("Case #%d: %d\n", ++t, ans);
  }
  return 0;
}
