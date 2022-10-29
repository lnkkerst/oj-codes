#include <cctype>
#include <cstdio>
#define int long long

int read() {
  int ret, fl = 1;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (fl = -1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
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
  int x;
  while (scanf("%d", &x) != EOF) {
    int ans = 0ll;
    for (int i = 1ll; i <= x - 1ll; ++i)
      ans += (1ll << (i - 1ll)) * ((1ll << (x - i)) - 1ll);
    print(ans), putchar('\n');
  }
}