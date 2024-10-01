#include <cstdio>
#define MAXN 600000

using namespace std;

int main() {
  int n, m, a[MAXN], ansn[MAXN] = {0}, ans = 1, x, y, event;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &event);
    if (event == 1) {
      scanf("%d%d", &x, &y);
      a[x] += y;
    }
    if (event == 2) {
      scanf("%d%d", &x, &y);
      for (int j = x; j <= y; j++) {
        ansn[ans] += a[j];
      }
      ans++;
    }
  }
  for (int i = 1; i < ans; i++) {
    printf("%d\n", ansn[i]);
  }
  return 0;
}
