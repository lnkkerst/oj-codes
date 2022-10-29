#include <cctype>
#include <cstdio>

const int INF = 0x7fffffff >> 1;
int e1[233][233], e2[233][233];
int n, m;

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
  n = read(), m = read();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      e1[i][j] = e2[i][j] = i == j ? 0 : INF;
  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read();
    e1[u][v] = e1[v][u] = e2[u][v] = e2[v][u] = read();
  }
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        if (e1[i][j] > e1[i][k] + e1[k][j])
          e1[i][j] = e1[i][k] + e1[k][j];
  // for(int i = 1; i <= n; ++i, putchar('\n'))
  //     for(int j = 1; j <= n; ++j, putchar(' '))
  //         print(e1[i][j]);
  //             for(int i = 1; i <= n; ++i, putchar('\n'))
  //     for(int j = 1; j <= n; ++j, putchar(' '))
  //         print(e2[i][j]);
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      ans += (e2[i][j] != INF && e1[i][j] != e2[i][j]);
  return print(ans), 0;
}