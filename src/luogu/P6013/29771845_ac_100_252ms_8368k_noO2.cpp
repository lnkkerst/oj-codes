#include <cctype>
#include <cstdio>
#define int long long

int ans = 0, lock[1000001] = {0}, money = 0;
int opt, x, m;

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
  m = read();
  for (int i = 1; i <= m; ++i) {
    opt = read(), x = read();
    money += lock[i];
    if (opt == 1)
      money += x;
    else if (opt == 2) {
      if (money >= x)
        money -= x;
      else
        ++ans;
    } else if (opt == 3)
      money -= x, lock[read()] += x;
  }
  print(ans);
  return 0;
}