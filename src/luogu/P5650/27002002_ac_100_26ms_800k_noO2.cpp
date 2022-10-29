#include <cctype>
#include <cstdio>

int max(int x, int y) { return x > y ? x : y; }

int main() {
  int last = -999999, ans = -999999;
  char ch;
  while ((ch = getchar()) != EOF) {
    int a = (ch == 48 ? 1 : -1);
    last = max(a, last + a);
    ans = max(last, ans);
  }
  printf("%d\n", ans);
  return 0;
}