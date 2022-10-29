#include <cstdio>
#include <cstring>
int main() {
  // freopen("president.in","r",stdin);
  // freopen("president.out","w",stdout);
  int n, i, ans;
  char tmp[100], anss[100] = {};
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", tmp);
    if (strcmp(tmp, anss) == 1 || strlen(tmp) > strlen(anss)) {
      strcpy(anss, tmp);
      ans = i;
    }
  }
  printf("%d\n%s", ans + 1, anss);
  fclose(stdin);
  fclose(stdout);
  return 0;
}