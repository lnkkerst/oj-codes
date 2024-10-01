#include <cctype>
#include <cstdio>

int n, m;
int a[20003];
int f[20003][1003];

int min(int x, int y) {
  return x < y ? x : y;
}

int max(int x, int y) {
  return x > y ? x : y;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  f[1][1] = a[1];
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= min(i, m); ++j) {
      if (!j) {
        f[i][0] = max(f[i][0], f[i - 1][0]);
      } else {
        f[i + j][0] = max(f[i + j][0], f[i][j]);
      }
      f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + a[i + 1]);
    }
  }
  printf("%d", f[n][0]);
  return 0;
}
