#include <cstdio>
#include <cstring>

const int MAXN = 1000010;

int next[MAXN] = {0}, l1, l2, j = 0;
char s1[MAXN], s2[MAXN];

int main() {
  scanf("%s%s", s1 + 1, s2 + 1);
  l1 = strlen(s1 + 1);
  l2 = strlen(s2 + 1);
  for (int i = 2; i <= l2; ++i) {
    while (j > 0 && s2[i] != s2[j + 1]) {
      j = next[j];
    }
    if (s2[j + 1] == s2[i]) {
      ++j;
    }
    next[i] = j;
  }
  j = 0;
  for (int i = 1; i <= l1; ++i) {
    while (j > 0 && s2[j + 1] != s1[i]) {
      j = next[j];
    }
    if (s2[j + 1] == s1[i]) {
      ++j;
    }
    if (j == l2) {
      printf("%d\n", i - l2 + 1);
      j = next[j];
    }
  }
  for (int i = 1; i <= l2; ++i) {
    printf("%d ", next[i]);
  }
  return 0;
}
