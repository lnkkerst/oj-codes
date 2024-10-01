#include <bits/stdc++.h>
using namespace std;
int kmp[2333333];
char a[2333333], b[2333333];
int main() {
  scanf("%s%s", a + 1, b + 1);
  int la = strlen(a + 1), lb = strlen(b + 1), j = 0;
  for (int i = 2; i <= lb; ++i) {
    while (j && b[i] != b[j + 1]) {
      j = kmp[j];
    }
    if (b[j + 1] == b[i]) {
      ++j;
    }
    kmp[i] = j;
  }
  j = 0;
  for (int i = 1; i <= la; ++i) {
    while (j > 0 && b[j + 1] != a[i]) {
      j = kmp[j];
    }
    if (b[j + 1] == a[i]) {
      ++j;
    }
    if (j == lb) {
      printf("%d\n", i - lb + 1), j = kmp[j];
    }
  }
  for (int i = 1; i <= lb; ++i) {
    printf("%d ", kmp[i]);
  }
  return 0;
}
