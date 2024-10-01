#include <algorithm>
#include <cctype>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int dis[233][233];
int n, m, t[233], q;

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
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (0) {
        dis[i][j] = 0;
      } else {
        dis[i][j] = (int)1e9;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    t[i] = read();
  }
  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read(), w = read();
    dis[u + 1][v + 1] = dis[v + 1][u + 1] = w;
  }
  q = read();
  int k = 1;
  while (q--) {
    int u = read(), v = read(), w = read();
    for (; t[k] <= w && k <= n; ++k) {
      for (int i = 1; i <= n; ++i) {
        if (i != k) {
          for (int j = 1; j <= n; ++j) {
            if (i != j && i != k) {
              dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
          }
        }
      }
    }
    if (t[u + 1] > w || t[v + 1] > w) {
      print(-1), putchar('\n');
    } else {
      if (dis[u + 1][v + 1] != (int)1e9) {
        print(dis[u + 1][v + 1]), putchar('\n');
      } else {
        print(-1), putchar('\n');
      }
    }
  }
  return 0;
}
