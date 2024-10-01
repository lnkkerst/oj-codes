#include <cstdio>

int f[110][2], n, m, w[110], v[110];

int max(int x, int y) {
  return x > y ? x : y;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &v[i], &w[i]);
  }
  for (int i = 1; i <= m; i++) {
    for (int j = n; j >= 0; j--) {
      if (j < v[i]) {
        f[j][0] = f[j][1];
      } else {
        f[j][0] = max(f[j][1], f[j - v[i]][1] + w[i]);
      }
    }
    for (int j = 0; j <= n; j++) {
      f[j][1] = f[j][0];
    }
  }

  printf("%d", f[n][0]);
}
