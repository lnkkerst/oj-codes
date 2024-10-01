#include <cctype>
#include <cstdio>

int read() {
  int ret, fl = 1;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (fl = -1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * fl;
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
  int t = read();
  while (t--) {
    int x = read(), ans = 0;
    for (int i = 1; i <= x; ++i) {
      int base = i, t = i;
      do {
        base += t % 10;
        t /= 10;
      } while (t);
      if (base == x) {
        ans = i;
        break;
      }
    }
    print(ans), putchar('\n');
  }
  return 0;
}
