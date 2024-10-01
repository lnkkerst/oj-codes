#include <cstdio>
#include <cstring>
using namespace std;
int main() {
  char s1[12], s2[12];
  scanf("%s", s1);
  int l = strlen(s1), i, j;
  if (s1[0] == '-') {
    printf("-");
    for (i = 0; i < l - 1; i++) {
      s1[i] = s1[i + 1];
    }
    l--;
  }
  for (i = l - 1, j = 0; i >= 0; i--) {
    if (s1[i] != '0') {
      s2[j] = s1[i];
      j++;
    }
  }
  printf("%s", s2);
  return 0;
}
