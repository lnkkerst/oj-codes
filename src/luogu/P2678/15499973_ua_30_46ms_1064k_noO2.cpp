#include <cstdio>

const int MAXN = 500000 + 10;

int a[MAXN], n, m, d, l, r, mid, ans;

bool check(int x) {
  int num = 0, t = 0;

  for (int i = 1; i <= n; i++) {
    t += a[i] - a[i - 1];

    if (t < x) {
      num++;

      if (num > m) {
        return 0;
      }
    } else {
      t = 0;
    }
  }

  t += a[n + 1] - a[n];

  if (t < x) {
    if (num == m || num == n) {
      return 0;
    }
  }

  return 1;
}

int main() {
  scanf("%d%d%d", &d, &n, &m);

  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }

  a[n + 1] = d;

  int l = 1, r = d;

  while (r - l > 1) {
    int mid = (l + r) >> 1;

    if (check(mid)) {
      l = mid + 1;
      ans = mid;
    }

    else {
      r = mid - 1;
    }
  }

  printf("%d", l);
}
