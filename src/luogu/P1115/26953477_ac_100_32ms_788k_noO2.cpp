#include <algorithm>
#include <cctype>
#include <cstdio>

int cnt;
char ch;

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

int main() {
  int n = read(), ans = read(), sum = ans;
  while (--n) {
    int x = read();
    sum = std::max(sum, 0);
    sum += x;
    ans = std::max(sum, ans);
  }
  print(ans);
  return 0;
}