#include <cstdio>
#define MAXN 10086

int n, h[MAXN], tot, ans, tmp;

void swap(int &x, int &y) {
  int t = x;
  x = y;
  y = t;
}

void l(int k) {
  for (; k > 1;) {
    if (h[k / 2] > h[k]) {
      swap(h[k / 2], h[k]);
      k /= 2;
    } else {
      return;
    }
  }
}

void r(int k) {
  for (; k * 2 <= tot;) {
    int j = 2 * k;
    if (j < tot && h[j + 1] < h[j]) {
      j++;
    }

    if (h[j] < h[k]) {
      swap(h[j], h[k]);
      k = j;
    } else {
      return;
    }
  }
}

int main() {
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    scanf("%d", &h[i]);
    tot++;
    l(i);
  }

  for (int i = 1; i < n; i++) {
    tmp = h[1];
    h[1] = h[tot--];
    r(1);
    tmp += h[1];
    h[1] = h[tot--];
    r(1);
    ans += tmp;
    h[++tot] = tmp;
    l(tot);
  }

  printf("%d\n", ans);

  return 0;
}
