#include <algorithm>
#include <cctype>
#include <cstdio>

int cnt;
char ch;

int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (f = -1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

void print(int x) {
  if (x < 0) {
    putchar('-'), x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

int main() {
  while (233) {
    ch = getchar();
    if (ch == '@') {
      break;
    }
    if (ch == '(') {
      ++cnt;
    }
    if (ch == ')') {
      --cnt;
      if (cnt < 0) {
        printf("NO\n");
        return 0;
      }
    }
  }
  printf("%s\n", cnt ? "NO" : "YES");
  return 0;
}
