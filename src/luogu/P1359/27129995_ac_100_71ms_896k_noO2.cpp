#include <algorithm>
#include <cctype>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int dis[233][233];
int n, m, t[233], q;

int read() {
  int ret, f = 1;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (f = -1);
  }
  for (ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0')
    ;
  return ret * f;
}

void print(int x) {
  if (x < 0) {
    putchar('-'), x = -x;
  }
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j) {
        dis[i][j] = 0;
      } else {
        dis[i][j] = (int)1e9;
      }
    }
  }
  for (int i = 1; i <= n - 1; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      dis[i][j] = read();
    }
  }
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  print(dis[1][n]);
  return 0;
}
