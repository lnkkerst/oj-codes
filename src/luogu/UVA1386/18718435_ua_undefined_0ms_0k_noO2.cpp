#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#define MAXN 100
#define int long long

using namespace std;

int read();
void print(int x);

int MOD, n, k, d;

struct Mat {
  int n, m;
  int dataee[MAXN][MAXN];
  Mat() { memset(dataee, 0, sizeof(dataee)); }
  Mat(int _n, int _m) {
    n = _n;
    m = _m;
    memset(dataee, 0, sizeof(dataee));
  }
  int *operator[](int x) { return dataee[x]; }
  Mat operator*(Mat b) {
    Mat c(n, b.m);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= b.m; ++j)
        for (int k = 1; k <= m; ++k)
          c[i][j] = (c[i][j] % MOD + dataee[i][k] * b[k][j] % MOD) % MOD;
    return c;
  }
  Mat pow(int k) {
    Mat tmp(n, n), res(n, n);
    for (int i = 1; i <= n; res[i][i] = 1, ++i)
      for (int j = 1; j <= n; ++j)
        tmp[i][j] = dataee[i][j];
    while (k) {
      if (k & 1)
        res = res * tmp;
      tmp = tmp * tmp;
      k >>= 1;
    }
    return res;
  }
  void printm() {
    for (int i = 1; i <= n; putchar('\n'), ++i)
      for (int j = 1; j <= m; putchar(' '), ++j)
        print(dataee[i][j]);
  }
  void printans() {
    for (int i = 1; i <= n; putchar(' '), ++i)
      print(dataee[i][1]);
    putchar('\n');
  }
};

int read() {
  int res;
  bool flag = 0;
  char ch;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (flag = 1);
  for (res = ch - '0'; isdigit(ch = getchar()); res *= 10, res += ch - '0')
    ;
  (flag == 1) && (res *= -1);
  return res;
}

void print(int x) {
  if (x < 0) {
    putchar('-');
    x *= -1;
  }
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

#undef int
int main() {
#define int long long
  n = read();
  MOD = read();
  d = read();
  k = read();
  Mat a(n, 1);
  Mat vi(n, n);
  vi[1][1] = 1;
  for (int i = 1; i <= d; ++i)
    vi[1][i + 1] = 1, vi[1][n + 1 - i] = 1;
  for (int i = 2; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      vi[i][j] = vi[1][(i - j + n) % n + 1];
  for (int i = 1; i <= n; ++i)
    a[i][1] = read();
  Mat ans = vi.pow(k);
  ans = ans * a;
  ans.printans();
  return 0;
}