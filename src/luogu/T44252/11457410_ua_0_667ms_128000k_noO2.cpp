#include <cstdio>
#define MAXN 10010

struct str {
  int color;
  int line[MAXN];
  int t = 0;
};

int main() {
  int n, m, b, l, r, x;
  scanf("%d%d", &n, &m);
  const int N = n + 1;
  str a[N];
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i].color);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d%d", &b, &l, &r, &x);
    if (b == 1)
      for (int j = l; j <= r; j++) {
        a[j].color = x;
        for (int k = 0; k < a[j].t; k++)
          a[a[j].line[k]].color = x;
      }
    else {
      a[0] = a[l];
      a[l] = a[r];
      a[r] = a[0];
      a[l].color = x;
      a[r].color = x;
      for (int j = 0; j < a[l].t; j++)
        a[a[l].line[j]].color = x;
      for (int j = 0; j < a[r].t; j++)
        a[a[r].line[j]].color = x;
      a[l].line[a[l].t] = r;
      a[l].t++;
      a[r].line[a[r].t] = l;
      a[r].t++;
    }
  }
  for (int i = 1; i <= n; i++)
    printf("%d ", a[i].color);
  printf("\n");
  for (int i = 1; i <= n; i++)
    printf("%d ", a[i].t);
  return 0;
}