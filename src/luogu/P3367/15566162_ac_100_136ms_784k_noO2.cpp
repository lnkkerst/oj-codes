#include <cstdio>
#define MAXN 10010
#define MAXM 200010

int f[MAXN], n, m;

int find(int x) {
  return f[x] == x ? x : f[x] = find(f[x]);
}

int main() {
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++) {
    f[i] = i;
  }

  for (int i = 1; i <= m; i++) {
    int t1, t2, t3;

    scanf("%d%d%d", &t1, &t2, &t3);

    if (t1 == 1) {
      f[find(t2)] = find(t3);
    } else {
      (find(t2) == find(t3)) ? printf("Y\n") : printf("N\n");
    }
  }

  return 0;
}
