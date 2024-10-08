#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#define MAXN 10
#define MOD 1000000007
#define int long long

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

int f[1000010] = {0, 1, 1};
int cnt = 3;

void stu_fib(int n) {
  for (int i = cnt; i <= n; ++i) {
    f[i] = (f[i - 1] % MOD + f[i - 2] % MOD) % MOD;
  }
  cnt = max(cnt, n);
}
#undef int
int main() {
#define int long long
  int t;
  scanf("%lld", &t);
  while (t--) {
    int num;
    scanf("%lld", &num);
    if (num <= 1000000) {
      stu_fib(num);
      printf("%lld\n", (f[num - 1] + f[num - 1] + f[num]) % MOD);
    } else {
      Mat v(2, 2);
      v[1][1] = v[1][2] = v[2][1] = 1;
      Mat tmp = v.pow(num - 2);
      int ans = tmp[1][1] * 2;
      tmp = tmp * v;
      printf("%lld\n", (ans + tmp[1][1]) % MOD);
    }
  }
  return 0;
}
