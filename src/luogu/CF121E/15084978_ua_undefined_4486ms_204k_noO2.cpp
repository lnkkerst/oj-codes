#include <cstdio>

const int MAXN = 100001;

bool pd(int x) {
  while (x != 0) {
    if (x % 10 != 4 && x % 10 != 7) {
      return 0;
    }

    x /= 10;
  }
  return 1;
}

int main() {
  int n, m, a[MAXN], l, r, d, ans;
  char q[6];

  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }

  for (int j = 1; j <= m; j++) {
    scanf("%s", q);

    if (q[0] == 'a') {
      scanf("%d%d%d", &l, &r, &d);

      for (int i = l; i <= r; i++) {
        a[i] += d;
      }
    }

    if (q[0] == 'c') {
      ans = 0;

      scanf("%d%d", &l, &r);

      for (int i = l; i <= r; i++) {
        ans += pd(a[i]);
      }

      printf("%d\n", ans);
    }
  }

  return 0;
}
