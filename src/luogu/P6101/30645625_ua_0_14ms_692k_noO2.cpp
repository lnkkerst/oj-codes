#include <cctype>
#include <cstdio>
#define int __int128_t

int a[233] = {0};

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
  char ch;
  int l;
  while ((ch = getchar()) != '\n')
    ++a[ch], ++l;
  int len = read(), t = -1;
  for (int i = 0; i < 233; ++i)
    if (a[i] > t)
      t = a[i];
  int ans = 0;
  while (l < len)
    l += t, t *= 2, ++ans;
  print(ans);
  return 0;
}