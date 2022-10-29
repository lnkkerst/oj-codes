#include <cstdio>
#include <cstring>
using namespace std;
int main() {
  char s[12];
  scanf("%s", s);
  int t = strlen(s) - 1, i, h = 0;
  if (s[0] == '-') {
    printf("-");
    h++;
  }
  while (s[t] == '0')
    t--;
  for (i = t; i >= h; i--)
    printf("%c", s[i]);
  return 0;
}