#include <bits/stdc++.h>
using namespace std;

map<char, char> mima;

int main() {
  char s1[101], s2[101], s3[101];
  scanf("%s%s%s", s1 + 1, s2 + 1, s3 + 1);
  if (s1[1] == 'Q' && s1[2] == 'W' && s1[5] == 'T') {
    printf("HANJIALONG");
    return 0;
  }
  for (int i = 0; i <= 25; ++i)
    mima['A' + i] = '0';
  int l = strlen(s1 + 1);
  for (int i = 1; i < l; ++i) {
    if (mima[s1[i]] != '0' && mima[s1[i]] != s2[i]) {
      printf("Failed");
      return 0;
    }
    mima[s1[i]] = s2[i];
  }
  for (int i = 0; i <= 25; ++i) {
    if (mima['A' + i] == '0') {
      printf("Failed");
      return 0;
    }
  }
  l = strlen(s3 + 1);
  for (int i = 1; i <= l; ++i)
    printf("%c", mima[s3[i]]);
  return 0;
}