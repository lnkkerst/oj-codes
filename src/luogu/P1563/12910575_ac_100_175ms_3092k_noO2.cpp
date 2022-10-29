#include <cstdio>
#define MAXN 100086

int main() {
  int n, m, s[MAXN], x, y;
  char cha[MAXN][20];
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%d%s", &s[i], cha[i]);
  int tmp = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    if (s[tmp] == x)
      tmp = (tmp - y + n) % n;
    else
      tmp = (tmp + y) % n;
  }
  printf("%s", cha[tmp]);
  return 0;
}