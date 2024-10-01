#include <cstdio>

int n, m, tree[500010] = {0};

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
  for (; x; x -= lowbit(x)) {
    res += tree[x];
  }
  return res;
}

int main() {

  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    add(i, a);
  }

  for (int i = 1; i <= m; i++) {
    int t, x, y;

    scanf("%d%d%d", &t, &x, &y);

    if (t == 1) {
      add(x, y);
    } else {
      printf("%d\n", find(y) - find(x - 1));
    }
  }

  return 0;
}
