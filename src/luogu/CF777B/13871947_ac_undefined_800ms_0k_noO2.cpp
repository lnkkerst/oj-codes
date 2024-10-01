#include <algorithm>
#include <cstdio>
#define MAXN 1010

int main() {
  int n, sn = 0, mn = 0;
  char s[MAXN], m[MAXN];

  scanf("%d%s%s", &n, s, m);

  std::sort(s, s + n);
  std::sort(m, m + n);

  for (int i = 0, j = 0; (i < n) && (j < n);) {
    if (m[j] > s[i]) {
      i++;
      j++;
      sn++;
    } else {
      j++;
    }
  }

  for (int i = 0, j = 0; (i < n) && (j < n);) {
    if (m[j] >= s[i]) {
      i++;
      j++;
    } else {
      j++;
      mn++;
    }
  }

  printf("%d\n%d", mn, sn);
  return 0;
}
