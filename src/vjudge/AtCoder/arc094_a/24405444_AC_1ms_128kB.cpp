#include <algorithm>
#include <cctype>
#include <cstdio>
using namespace std;

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
  int a = read(), b = read(), c = read();
  if (a < b) {
    swap(a, b);
  }
  if (b < c) {
    swap(b, c);
  }
  if (a < b) {
    swap(a, b);
  }
  // printf("%d %d %d\n", a, b, c);
  int ans = a - b;
  c += ans;
  if ((a - c) & 1) {
    ans += (a - c + 3) >> 1;
  } else {
    ans += (a - c) >> 1;
  }
  print(ans);
  return 0;
}
