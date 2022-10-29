#include <cstdio>
#include <cstring>
int main() {
  int n, ansn = 1, lt, la;
  bool flag = 0;
  char ans[100] = {}, tmp[100];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    lt = strlen(tmp);
    la = strlen(ans);
    if (lt > la) {
      for (int j = 0; j < lt; j++)
        ans[j] = tmp[j];
      ansn = i + 1;
      continue;
    } else if (la > lt)
      continue;
    else
      for (int j = 0; j < lt; j++)
        if (tmp[j] > ans[j]) {
          flag = 1;
          break;
        }
    if (flag == 1) {
      for (int j = 0; j < lt; j++)
        ans[j] = tmp[j];
      ansn = i + 1;
      continue;
    }
  }
  printf("%d\n%s", ansn, ans);
  return 0;
}