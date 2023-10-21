/*********************************************************************
    $PROGRAM$:
    $COPYRIGHT$:
    $AUTHOR$:
    $DATETIME$: 2023/10/15 17:39:03
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
const ll maxn = 10001000;
const ll inf = 0x3f3f3f3f3f3f3f3fll;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
ll a[101][101], n, m, s, cnt, minx, maxx;
ll read() {
  char ch = getchar();
  ll xx = 0, ff = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      ff = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    xx = xx * 10 + ch - '0';
    ch = getchar();
  }
  return xx * ff;
}
int main() {
  n = read();
  m = read();
  ll k = m;
  for (int i = 1; i <= n; i += 2) {

    a[i][k] = 1;
    a[i + 1][k] = 1;
    k--;
    if (k == 0) {
      k = 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
