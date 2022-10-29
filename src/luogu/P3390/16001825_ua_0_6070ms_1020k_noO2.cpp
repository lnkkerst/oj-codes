#include <cctype>
#include <cstdio>
#include <cstring>
#define MAXN 110
#define num ch - '0'
int n, k;
int read() {
  int res;
  char ch;
  bool flag = 0;
  while (!isdigit(ch = getchar()))
    (ch == '-') && (flag = true);
  for (res = num; isdigit(ch = getchar()); res = res * 10 + num)
    ;
  (flag) && (res = -res);
  return res;
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

struct Matrix {
  int n, m;
  int a[MAXN][MAXN];
  Matrix() { memset(a, 0, sizeof(a)); }
  Matrix(int _n, int _m) {
    n = _n;
    m = _m;
    memset(a, 0, sizeof(a));
  }
  int *operator[](int x) { return a[x]; }
  Matrix operator*(Matrix b) {
    Matrix c(n, b.m);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= b.m; j++) {
        for (int k = 1; k <= m; k++) {
          c[i][j] += a[i][k] * b[k][j];
        }
      }
    }
    return c;
  }
};

Matrix ksm(Matrix a, int b) {
  Matrix ret(a.n, a.n);
  for (int i = 1; i <= a.n; i++)
    ret[i][i] = 1;
  while (b) {
    if (b & 1)
      ret = ret * a;
    a = a * a;
    b >>= 1;
  }
  return ret;
}

int main() {
  n = read();
  k = read();
  Matrix a = Matrix(n, n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      a[i][j] = read();
  ksm(a, k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      print(a[i][j]), putchar(' ');
    putchar('\n');
  }
  return 0;
}