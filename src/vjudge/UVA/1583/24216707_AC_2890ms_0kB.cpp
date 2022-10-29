#include <cctype>
#include <cstdio>

int cvt[100010] = {0};

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

int spilt(int x) {
  int ret = 0;
  do
    ret += x % 10, x /= 10;
  while (x);
  return ret;
}

int get(int x) {
  if (cvt[x])
    return cvt[x];
  else
    cvt[x] = x + spilt(x);
  return cvt[x];
}

int solve(int n) {
  for (int i = 1; i <= n; ++i)
    if (get(i) == n)
      return i;
  return 0;
}

int main() {
  int t = read();
  while (t--)
    print(solve(read())), putchar('\n');
  return 0;
}