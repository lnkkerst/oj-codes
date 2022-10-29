#include <algorithm>
#include <cctype>
#include <cstdio>
#define num ch - '0'
int read() {
  int res;
  bool flag = 0;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (flag = 1);
  for (res = num; isdigit(ch = getchar()); res *= 10, res += num)
    ;
  (flag == 1) && (res *= -1);
  return res;
}
int main() {
  int n = read();
  while (n--)
    if (read() & 1)
      printf("zs wins\n");
    else
      printf("pb wins");
  return 0;
}