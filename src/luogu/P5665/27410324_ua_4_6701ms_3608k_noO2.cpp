#include <cctype>
#include <cstdio>
using namespace std;

int n, typ, a[500010];
int sa[500010], top;

inline int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (f = -1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

inline void print(int x) {
  if (x < 0) {
    putchar('-'), x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

int main() {
  n = read(), typ = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] >= sa[top]) {
      sa[++top] = a[i];
    } else if (i + 1 <= n && a[i] + sa[top] <= a[i + 1]) {
      sa[top] += a[i];
    } else {
      int tmp = 0, j;
      for (j = i; j <= n; ++j) {
        tmp += a[j];
        if (tmp >= sa[top] || (j + 1 <= n && tmp + sa[top] <= a[j + 1])) {
          break;
        }
      }
      if (tmp >= sa[top]) {
        sa[++top] = tmp, i = j;
      } else {
        sa[top] += tmp;
      }
      i = j;
    }
  }
  int ans = 0;
  for (int i = 1; i <= top; ++i) {
    ans += sa[i] * sa[i];
  }
  print(ans);
  return 0;
}
