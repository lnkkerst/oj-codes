#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#define MAXN 10
#define MOD 1000000007

using namespace std;

struct Mat {
  int n, m;
  int dataee[MAXN][MAXN];
  Mat() {
    memset(dataee, 0, sizeof(dataee));
  }
  Mat(int _n, int _m) {
    n = _n;
    m = _m;
    memset(dataee, 0, sizeof(dataee));
  }
  int *operator[](int x) {
    return dataee[x];
  }
  Mat operator*(Mat b) {
    Mat c(n, b.m);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= b.m; ++j) {
        for (int k = 1; k <= m; ++k) {
          c[i][j] = (c[i][j] % MOD + dataee[i][k] * b[k][j] % MOD) % MOD;
        }
      }
    }
    return c;
  }
  Mat pow(int k) {
    Mat tmp(n, n), res(n, n);
    for (int i = 1; i <= n; res[i][i] = 1, ++i) {
      for (int j = 1; j <= n; ++j) {
        tmp[i][j] = dataee[i][j];
      }
    }
    while (k) {
      if (k & 1) {
        res = res * tmp;
      }
      tmp = tmp * tmp;
      k >>= 1;
    }
    return res;
  }
};

int n, k;

int read() {
  int res;
  bool flag = 0;
  char ch;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (flag = 1);
  }
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
  if (x > 9) {
    print(x / 10);
  }
  putchar(x % 10 + '0');
}

int main() {
  int t = read();
  Mat a(3, 1), v(3, 3);
  a[3][1] = a[2][1] = a[1][1] = 1;
  v[1][1] = v[1][3] = v[2][1] = v[3][2] = 1;
  while (t--) {
    Mat tmp = v.pow(read() - 3) * a;
    print(tmp[1][1]);
    putchar('\n');
  }
  return 0;
}
