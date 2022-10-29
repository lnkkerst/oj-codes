#include <cstdio>
#include <cstring>

int x, t;
char str[100010];

void solve(int len, char s[]) {
  for (int i = 1; i <= len; ++i)
    s[len + i] = s[i];
  int i = 1, j = 2;
  while (i <= len && j <= len) {
    int k = 0;
    while (k < len && s[i + k] == s[j + k])
      ++k;
    if (k == len)
      break;
    if (s[i + k] > s[j + k])
      i += k + 1, (i == j) && ++i;
    else
      j += k + 1, (i == j) && ++j;
  }
  printf("%d\n", (i < j ? i : j) - 1);
  return;
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%s", &x, str + 1);
    solve(x, str);
  }
  return 0;
}