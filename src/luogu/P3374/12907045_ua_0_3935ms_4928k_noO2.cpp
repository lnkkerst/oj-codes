#include <cstdio>
#define MAXN 600000

int main() {
  int s[MAXN], n, m, ans[MAXN] = {0}, ansn = 1;

  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++) {
    scanf("%d", &s[i]);
  }
  for (int i = 1; i <= m; i++) {
    int event, x, y;
    scanf("%d%d%d", &event, &x, &y);
    if (event == 1) {
      s[x] += y;
    }
    if (event == 2) {
      for (int j = x; j <= y; j++) {
        ans[ansn] += s[j];
      }
      ansn++;
    }
  }
  for (int i = 1; i < ansn; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
