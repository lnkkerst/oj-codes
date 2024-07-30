/*********************************************************************
    $PROGRAM$:
    $COPYRIGHT$:
    $AUTHOR$:
    $DATETIME$: 2024/7/18 12:45:45
    $DESCRIPTION$:
*********************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#ifdef Debug
#define D() cerr << __LINE__ << endl;
#else
#define D()
#endif
#define ll long long
#define ull unsigned long long
using namespace std;
const ll maxn = 1000100;
const ll inf = 0x3f3f3f3f3f3f3f3fll;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
char a[4][maxn];
ll f[4][maxn], ans;
ll n, m, s, cnt, minx, maxx;
ll read() {
  char ch = getchar();
  ll xx = 0, ff = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      ff = -1;
    }
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    xx = xx * 10 + ch - '0';
    ch = getchar();
  }
  return xx * ff;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= 2; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      if (a[i][j] == 'R') {
        f[i][j] = 1;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 2; ++j) {
      if (a[j][i] == 'W') {
        continue;
      }
    }
    if (a[1][i] == 'W' && a[2][i] == 'W') {
      continue;
    }
    if (a[1][i] == 'R' && a[2][i] == 'W') {
      f[1][i] = max(f[1][i], f[1][i - 1] + 1);
    }
    if (a[1][i] == 'W' && a[2][i] == 'R') {
      f[2][i] = max(f[2][i], f[2][i - 1] + 1);
    }
    if (a[1][i] == 'R' && a[2][i] == 'R') {
      if (a[1][i - 1] == 'W' && a[2][i - 2] == 'R') {
        f[2][i] = max(f[2][i - 1] + 1, f[2][i]);
        f[1][i] = max(f[1][i], f[2][i] + 1);
      } else {
        if (a[1][i - 1] == 'R' && a[2][i - 1] == 'W') {
          f[1][i] = max(f[1][i], f[1][i - 1] + 1);
          f[2][i] = max(f[2][i], f[1][i] + 1);
        } else {
          if (a[1][i - 1] == 'R' && a[2][i - 1] == 'R') {
            f[1][i] = max(f[1][i - 1] + 1, f[2][i - 1] + 2);
            f[2][i] = max(f[2][i - 1] + 1, f[1][i - 1] + 2);
          } else {
            f[1][i] = 2;
            f[2][i] = 2;
          }
        }
      }
    }
  }
  for (int i = 1; i <= 2; ++i) {
    for (int j = 1; j <= n; ++j) {
      ans = max(ans, f[i][j]);
    }
  }
  ans--;
  ans = max(0ll, ans);
  cout << ans;
  return 0;
}
