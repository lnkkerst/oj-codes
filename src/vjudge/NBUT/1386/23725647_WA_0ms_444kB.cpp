#include <cstdio>
#define MAXN 200

int x[MAXN], n;
bool y[MAXN], dx[MAXN], dy[MAXN];

void dfs(int step) {
  if (step > n) {
    for (int i = 1; i <= n; i++)
      printf("%d", x[i]);
    printf("\n");
  }
  for (int i = 1; i <= n; i++) {
    if (!y[i] && !dx[i + step] && !dy[step - i + n]) {
      x[step] = i;
      y[i] = 1;
      dx[i + step] = 1;
      dy[step - i + n] = 1;
      dfs(step + 1);
      y[i] = 0;
      dx[i + step] = 0;
      dy[step - i + n] = 0;
    }
  }
}

int main() {
  scanf("%d", &n);
  dfs(1);
  return 0;
}