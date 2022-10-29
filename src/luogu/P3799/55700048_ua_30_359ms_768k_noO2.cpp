#include <iostream>
using namespace std;
#define int __int128_t

int n, b[5010], ans;

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
  n = read();
  int ma = 0;
  for (int i = 1; i <= n; ++i) {
    int x = read();
    ++b[x];
    ma = max(ma, x);
  }
  for (int i = ma; i >= 1; --i) {
    if (b[i] < 2) {
      continue;
    }
    for (int j = i - 1; j >= (i + 1) / 2; --j) {
      if (j != i - j) {
        ans += ((b[i] * (b[i] - 1)) >> 1) * b[j] * b[i - j];
      } else if (b[j] >= 2) {
        ans += ((b[i] * (b[i] - 1)) >> 1) * ((b[j] * (b[j] - 1)) >> 1);
      }
    }
  }
  print(ans);
  return 0;
}