#include <cstdio>

void read(int &x) {
  int f = 1;

  x = 0;

  char s = getchar();

  while (s < '0' || s > '9') {
    if (s == '-') {
      f = -1;
    }

    s = getchar();
  }

  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';

    s = getchar();
  }

  x *= f;
}

void print(int x) {
  if (x < 0) {
    putchar('-');
    x *= -1;
  }

  if (x > 9) {
    print(x / 10);
  }

  putchar(x % 10 + '0');
}

int main() {
  int n, m, tree[500010] = {0};

  read(n);
  read(m);

  for (int i = 1; i <= n; i++) {
    int a;

    read(a);

    for (int j = i; j <= n; j++) {
      tree[j] += a;
    }
  }

  for (int t = 1; t <= m; t++) {
    int e;

    read(e);

    if (e == 1) {
      int x, y, k;

      read(x);
      read(y);
      read(k);

      int tmp = y - x + 1;

      for (int i = 1; i <= tmp; i++) {
        tree[i + x - 1] += k * i;
      }

      tmp *= k;

      for (int i = x + tmp / k; i <= n; i++) {
        tree[i] += tmp;
      }
    } else {
      int x;

      read(x);

      printf("%d\n", tree[x] - tree[x - 1]);
    }
  }
  return 0;
}
