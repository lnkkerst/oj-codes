#include <cctype>
#include <cmath>
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
  int t = read();
  while (t--) {
    int a = read(), b = read(), mul = a * b;
    int base = (int)sqrt(mul), ans = (base << 1);
    // if(base == a && base == b) --ans;
    // // if(abs(a - b) == 1 && (base == a || base == b)) --ans;
    // if(base * base == mul - 1) --ans;
    // if(base * base == mul) ans -= 2;
    if (base * base == mul) {
      if (a == b)
        ans -= 2;
      else
        ans -= 3;
    } else if (base * (base + 1) < mul)
      ans -= 1;
    else
      ans -= 2;
    print(ans), putchar('\n');
  }
  return 0;
}