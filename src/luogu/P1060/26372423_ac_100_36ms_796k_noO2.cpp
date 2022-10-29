#include <cstdio>

int n, m, f[100010];
int w[100010], v[100010];

int max(int x, int y) { return x > y ? x : y; }

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &w[i], &v[i]);
    v[i] *= w[i];
  }
  for (int i = 1; i <= m; ++i)
    for (int j = n; j >= w[i]; --j)
      f[j] = max(f[j], f[j - w[i]] + v[i]);
  printf("%d\n", f[n]);
}