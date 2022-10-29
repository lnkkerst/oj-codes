#include <cstring>
#include <iostream>
#define int long long
using namespace std;

const int MOD = (int)1e9 + 7;
int n = 2;

struct Mat {
  int m[10][10];
  int *operator[](const int x) { return m[x]; }
  Mat() { memset(m, 0, sizeof(m)); }
};

int mod(int x) { return (x % MOD + MOD) % MOD; }

Mat mul(Mat a, Mat b) {
  Mat ret;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      for (int k = 1; k <= n; ++k)
        ret[i][j] = mod(ret[i][j] + mod(a[i][k]) * mod(b[k][j]));
  return ret;
}

signed main() {
  int f1, f2, x;
  cin >> f1 >> f2 >> x;
  Mat ans, base;
  ans[1][1] = f2, ans[1][2] = f1;
  base[1][1] = 1, base[2][1] = -1, base[1][2] = 1;
  x = max(x - 2, 0ll);
  while (x) {
    if (x & 1)
      ans = mul(ans, base);
    base = mul(base, base);
    x >>= 1;
  }
  cout << mod(ans[1][1]);
  return 0;
}