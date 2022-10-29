#include <cstdio>

int f[30010], n, m, ans = 0;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void init(int x) {
  for (int i = 1; i <= x; ++i)
    f[i] = i;
}

void merge(int x, int y) { f[find(x)] = f[y]; }

int main() {
  scanf("%d%d", &n, &m);
  int opt, x, y;
  init(n * 3);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d", &opt, &x, &y);
    if (x > n || y > n) {
      ++ans;
      continue;
    }
    if (opt == 1) {
      if (find(x + n) == find(y) || find(x + n + n) == find(y)) {
        ++ans;
        continue;
      }
      merge(x, y);
      merge(x + n, y + n);
      merge(x + n + n, y + n + n);
    }
    if (opt == 2) {
      if (find(x) == find(y) || find(x) == find(y + n)) {
        ++ans;
        continue;
      }
      merge(x + n, y);
      merge(x + n + n, y + n);
      merge(x, y + n + n);
    }
  }
  printf("%d\n", ans);
  return 0;
}