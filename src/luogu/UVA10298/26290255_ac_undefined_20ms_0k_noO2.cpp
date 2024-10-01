#include <cstdio>
#include <cstring>
char s[1000010];
int kmp[1000010];
int main() {

  while (233) {
    scanf("%s", s + 1);
    if (s[1] == '.') {
      return 0;
    }
    memset(kmp, 0, sizeof(kmp));
    int len = strlen(s + 1), j = 0;
    for (int i = 2; i <= len; ++i) {
      while (j && s[i] != s[j + 1]) {
        j = kmp[j];
      }
      if (s[j + 1] == s[i]) {
        ++j;
      }
      kmp[i] = j;
    }
    printf("%d\n", len % (len - kmp[len]) ? 1 : len / (len - kmp[len]));
  }
}
