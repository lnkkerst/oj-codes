#include <cctype>
#include <cstdio>
#include <queue>
using namespace std;

int n, piao[233333], time[233333];
int cnt, ans, top = 1;
bool used[233333];

inline int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (f = -1);
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

inline void print(int x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    int opt = read(), w = read(), t = read();
    bool f = 1;
    if (opt) {
      for (int i = top; i <= cnt; ++i)
        if (!used[i] && piao[i] >= w && t - time[i] <= 45) {
          used[i] = 1;
          f = 0;
          break;
        }
    } else
      piao[++cnt] = w, time[cnt] = t;
    if (f)
      ans += w;
    while (top <= cnt && t - time[top] > 45)
      ++top;
  }
  print(ans);
  return 0;
}