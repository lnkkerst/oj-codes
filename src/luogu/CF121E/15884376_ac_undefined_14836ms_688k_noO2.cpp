#include <cstdio>
#define MAXN 100010

int n, m, tree[MAXN], a[MAXN];
bool pd[MAXN];
const int lcn[] = {4,    7,    44,   47,   74,   77,   444,  447,  474,  744,
                   477,  747,  774,  777,  4444, 4447, 4474, 4744, 7444, 4477,
                   4747, 7447, 4774, 7474, 7744, 4777, 7477, 7747, 7774, 7777};

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
  for (int i = 0; i < 30; i++) {
    pd[lcn[i]] = 1;
  }

  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (pd[a[i]]) {
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
        if (pd[a[j]]) {
          add(j, -1);
        }
        a[j] += num;
        if (pd[a[j]]) {
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
