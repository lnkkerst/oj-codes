#include <cctype>
#include <cstdio>

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

bool pd(int x) {
  int base = 1;
  while (x > 0) {
    x -= base, base += 2;
  }
  return !x;
}

int main() {
  int n = read(), m = read();
  while (n || m) {
    if (n * n >= m * 4 && pd(n * n - m * 4)) {
      puts("Yes");
    } else {
      puts("No");
    }
    n = read(), m = read();
  }
  return 0;
}
