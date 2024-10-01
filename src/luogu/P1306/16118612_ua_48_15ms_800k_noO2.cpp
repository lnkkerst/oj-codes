#include <cctype>
#include <cstdio>
#define MOD 100000000
#define num ch - '0'
int read() {
  int res;
  char ch;
  bool flag = 0;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (flag = true);
  }
  for (res = num; isdigit(ch = getchar()); res = res * 10 + num)
    ;
  (flag) && (res = -res);
  return res;
}
void print(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

int gcd(int x, int y) {
  return !y ? x : gcd(y, x % y);
}

int f[10000000] = {0, 1};

int main() {
  int n = read(), m = read();
  int tmp = gcd(n, m);
  for (int i = 2; i <= tmp; i++) {
    f[i] = f[i - 1] + f[i - 2] % MOD;
  }
  print(f[tmp]);
  return 0;
}
