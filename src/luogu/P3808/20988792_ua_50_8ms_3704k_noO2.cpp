#include <cstdio>
#include <cstring>

char a[100][1000010], pl[1000010];
int n, ans = 0;

bool match(char *s, char *p) {
  int sl = strlen(s), pl = strlen(p);
  int i = 0, j = 0;
  while (i < pl && j < sl) {
    if (s[j] == p[i]) {
      ++i;
      ++j;
    } else {
      i -= j - 1;
      j = 0;
    }
  }
  return (j == sl);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", a[n]);
  }
  scanf("%s", pl);
  for (int i = 1; i <= n; i++) {
    ans += match(a[i], pl);
  }
  printf("%d", ans);
  return 0;
}
