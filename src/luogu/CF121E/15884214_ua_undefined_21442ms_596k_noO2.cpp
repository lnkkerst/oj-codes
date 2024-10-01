#include <cstdio>
#define MAXN 100010

int n, m, tree[MAXN], a[MAXN];

bool pd(int x) {
  while (x != 0) {
    if (x % 10 != 4 && x % 10 != 7) {
      return 0;
    }

    x /= 10;
  }
  return 1;
}

int lowbit(int x) {
  return x & -x;
}

void add(int x, int y) {
  for (; x <= n; x += lowbit(x)) {
    tree[x] += y;
  }
}

int find(int x) {
  int res = 0;
  for (; x > 0; x -= lowbit(x)) {
    res += tree[x];
  }
  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (pd(a[i])) {
      add(i, 1);
    }
  }

  char e[6];

  for (int i = 1; i <= m; i++) {
    scanf("%s", e);
    if (e[0] == 'a') {
      int l, r, num;
      scanf("%d%d%d", &l, &r, &num);
      for (int j = l; j <= r; j++) {
        if (pd(a[j])) {
          add(j, -1);
        }
        a[j] += num;
        if (pd(a[j])) {
          add(j, 1);
        }
      }
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", find(r) - find(l - 1));
    }
  }

  return 0;
}
