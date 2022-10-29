#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strMatch(char ori[], char str[], int pos[],
             int *tot) { //文本串、模式串、保存出现下标的数组、出现的次数
  int l1 = 0, l2 = 0, j = 0, ret = 0;
  while (ori[l1])
    ++l1;
  while (str[l2])
    ++l2;
  if (l2 > l1) {
    if (tot != NULL)
      *tot = 0;
    return 0;
  }
  int *nex = (int *)malloc(sizeof(int) * l2);
  nex[0] = nex[1] = 0;
  for (int i = 1; i < l2; ++i) {
    while (j && str[i] != str[j])
      j = nex[j];
    nex[i + 1] = str[i] == str[j] ? ++j : 0;
  }
  j = 0;
  for (int i = 0; i < l1; ++i) {
    while (j && str[j] != ori[i])
      j = nex[j];
    j += ori[i] == str[j];
    if (j == l2) {
      if (pos)
        pos[ret++] = i - l2 + 1;
      j = nex[j];
    }
  }
  if (tot != NULL)
    *tot = ret;
  free(nex);
  return ret;
}
char wd[16];
char ltr[1000006];
int pos[1000006];
int main() {

  scanf("%s\n%[^\n]", wd + 1, ltr + 1);
  int l1 = strlen(wd + 1), l2 = strlen(ltr + 1);
  for (int i = 0; i < l1; ++i)
    wd[i] = tolower(wd[i]);
  for (int i = 0; i < l2; ++i)
    ltr[i] = tolower(ltr[i]);
  wd[0] = ' ', wd[++l1] = ' ', wd[++l1] = 0;
  ltr[0] = ' ', ltr[++l2] = ' ', ltr[++l2] = 0;
  int ans = strMatch(ltr, wd, pos, NULL);
  if (!ans) {
    puts("-1");
    return 0;
  }
  printf("%d %d", ans, pos[0]);
  return 0;
}