#include <cctype>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int read() {
  int ret;
  char ch;
  bool flag = 0;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (flag = 1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  (flag == 1) && (ret = -ret);
  return ret;
}

void print(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

int main() {
  int p1 = read(), p2 = read(), p3 = read();
  char s[200];
  scanf("%s", s + 1);
  for (int i = 1; i <= (int)strlen(s + 1); ++i) {
    if (s[i] == '-') {
      if (s[i - 1] >= s[i + 1] || isdigit(s[i - 1]) ^ isdigit(s[i + 1]))
        putchar('-');
      else if (p1 == 3) {
        for (int j = 1; j <= p2 * (s[i + 1] - s[i - 1] - 1); ++j)
          putchar('*');
      } else if (isdigit(s[i - 1])) {
        if (p3 == 1)
          for (int j = s[i - 1] + 1; j <= s[i + 1] - 1; ++j)
            for (int k = 1; k <= p2; ++k)
              putchar(j);
        else
          for (int j = s[i + 1] - 1; j >= s[i - 1] + 1; --j)
            for (int k = 1; k <= p2; ++k)
              putchar(j);
      } else if (p1 == 2) {
        if (p3 == 1)
          for (int j = ((int)s[i - 1] % 96 ? s[i - 1] - 32 : s[i - 1]) + 1;
               j <= (s[i + 1] % 96 ? s[i + 1] - 32 : s[i + 1]) - 1; ++j)
            for (int k = 1; k <= p2; ++k)
              putchar(j);
        else
          for (int j = (s[i + 1] % 96 ? s[i + 1] - 32 : s[i + 1]) - 1;
               j >= (s[i - 1] % 96 ? s[i - 1] - 32 : s[i - 1]) + 1; --j)
            for (int k = 1; k <= p2; ++k)
              putchar(j);
      } else {
        if (p3 == 1)
          for (int j = ((int)s[i - 1] % 96 ? s[i - 1] : s[i - 1] + 32) + 1;
               j <= ((int)s[i + 1] % 96 ? s[i + 1] : s[i + 1]) - 1; ++j)
            for (int k = 1; k <= p2; ++k)
              putchar(j);
        else
          for (int j = (s[i + 1] % 96 ? s[i + 1] : s[i + 1] + 32) - 1;
               j >= (s[i - 1] % 96 ? s[i - 1] : s[i - 1] + 32) + 1; --j)
            for (int k = 1; k <= p2; ++k)
              putchar(j);
      }

    } else
      putchar(s[i]);
  }
}