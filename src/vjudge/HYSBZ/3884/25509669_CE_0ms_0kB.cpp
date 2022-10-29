#include <iostream>
#define int __int128_t
using namespace std;

int read() {
  int ret, fl = 1;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (fl = -1);
  ret = ch - '0';
  while (isdigit(ch = getchar()))
    ret *= 10, ret += ch - '0';
  return ret * fl;
}

void print(int x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

signed main() {
  int t = read();
  while (t--) {
    print(((__int128_t)1 << 126) % read());
    puts("");
  }
  return 0;
}