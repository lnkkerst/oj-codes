#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#define int __int128
using namespace std;

int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (f = -1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

void print(int x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

signed main() {
  int n = read(), sum = 0;
  for (int i = 1; i <= n; ++i)
    sum += read();
  print(sum % n == 0 ? sum / n : sum / n + 1);
  return 0;
}