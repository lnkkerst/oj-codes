#include <cmath>
#include <iostream>
using namespace std;

int n, m;
int a[100010];
int f[100010][40];
int l2[100010] = {-1};

inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}

int main() {
  //    ios::sync_with_stdio(false);
  //    cin.tie(nullptr);
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) {
    l2[i] = l2[i >> 1] + 1;
  }
  for (int i = 1; i <= n; ++i) {
    f[i][0] = a[i] = read();
  }
  for (int j = 1; (1 << j) <= n; ++j) {
    for (int i = 1; i <= n - (1 << j) + 1; ++i) {
      f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }
  }
  for (int i = 1; i <= m; ++i) {
    int l = read(), r = read();
    int lo = l2[r - l + 1];
    cout << max(f[l][lo], f[r - (1 << lo) + 1][lo]) << endl;
  }
  return 0;
}
