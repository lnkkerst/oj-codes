#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 15

using namespace std;

double eps = 1e-7;

struct Mat {
  double dat[MAXN][MAXN];
  int n, m;
  Mat() { memset(dat, 0, sizeof(dat)); }
  Mat(int _n, int _m) {
    n = _n;
    m = _m;
    memset(dat, 0, sizeof(dat));
  }
  Mat(int _gu) {
    n = _gu;
    m = _gu + 1;
    memset(dat, 0, sizeof(dat));
  }
  double *operator[](int x) { return dat[x]; }
  double x[MAXN];
  bool gauss() {
    for (int i = 1, pos; i <= n; ++i) {
      pos = i;
      for (int j = i + 1; j <= n; ++j)
        if (fabs(dat[j][i]) > fabs(dat[pos][i]))
          pos = j;
      for (int j = i; j <= n + 1; ++j)
        swap(dat[pos][j], dat[i][j]);
      if (!dat[i][i])
        return false;
      for (int j = i + 1; j <= n; ++j)
        if (fabs(dat[j][i]) > eps) {
          double p = dat[i][i] / dat[j][i];
          for (int k = i; k <= n + 1; ++k)
            dat[j][k] = dat[i][k] - dat[j][k] * p;
        }
    }
    for (int i = n; i >= 1; --i) {
      x[i] = dat[i][n + 1];
      for (int j = i + 1; j <= n; ++j)
        x[i] -= x[j] * dat[i][j];
      x[i] /= dat[i][i];
    }
    return true;
  }
};

int main() {
  int n;
  double map[MAXN][MAXN];
  scanf("%d", &n);
  for (int i = 1; i <= n + 1; ++i)
    for (int j = 1; j <= n; ++j)
      scanf("%lf", &map[i][j]);
  Mat ans(n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      ans[i][j] = (map[i][j] - map[i + 1][j]) * 2.0;
      ans[i][n + 1] += (map[i][j] * map[i][j] - map[i + 1][j] * map[i + 1][j]);
    }
  }
  for (int i = 1; i <= n; ++i, printf("\n"))
    for (int j = 1; j <= n + 1; ++j)
      printf("%lf ", ans[i][j]);
  ans.gauss();
  for (int i = 1; i <= n; ++i)
    printf("%.3lf ", ans.x[i]);
  return 0;
}