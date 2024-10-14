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

struct P {
  ll val;
  int biao;
};
P a[maxn], b[maxn];
ll k, n, f[200010][12][12];
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

bool cmp(P x, P y) {
  return x.val > y.val;
}

int main() {
  n = read();

  k = read();
  k = min(k, n);

  for (int i = 1; i <= n; ++i) {
    a[i].val = read();
    a[i].biao = 1;
  }
  for (int i = 1; i <= n; ++i) {
    b[i].val = read();
    b[i].biao = 2;
  }

  sort(a + 1, a + 1 + n, cmp);
  sort(b + 1, b + 1 + n, cmp);
  n *= 2;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      for (int r = 1; r <= k; ++r) {
        f[i][j][k] = inf;
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    ll numb = i / 2;
    ll numa = i - numb;
    cout << i << ' ' << numa << ' ' << numb << endl;
    for (int j = 0; j <= min(k, numa); ++j) {
      for (int r = 0; r <= min(k, numb); ++r) {
        ll bana = numb - r;
        ll banb = numa - j;
        ll tmp;
        if (i % 2 == 1) {
          tmp = -inf;
          if (f[i - 1][j][r] != inf && f[i - 1][j][r] != -inf) {
            tmp = f[i - 1][j][r];
          }
          if (j != 0 && f[i - 1][j - 1][r] != inf
              && f[i - 1][j - 1][r] != -inf) {
            tmp = max(tmp, f[i - 1][j - 1][r] + a[j - 1 + bana + 1].val);
          }
          if (i == 3 && j == 1 && r == 0) {
            cout << tmp << endl;
            cout << a[j - 1 + bana + 1].val << endl;
          }
          f[i][j][r] = tmp;
        } else {
          tmp = inf;
          if (f[i - 1][j][r] != inf && f[i - 1][j][r] != -inf) {
            tmp = f[i - 1][j][r];
          }
          if (r != 0 && f[i - 1][j][r - 1] != inf
              && f[i - 1][j][r - 1] != -inf) {
            tmp = min(tmp, f[i - 1][j][r - 1] - b[r - 1 + banb + 1].val);
          }
          f[i][j][r] = tmp;
        }
      }
    }
  }

  cout << f[3][1][0] << endl;

  for (int l = 0; l <= n; ++l) {
    for (int i = 0; i <= k; ++i) {
      for (int j = 0; j <= k; ++j) {
        cout << l << ' ' << i << ' ' << j << ' ' << f[l][i][j] << endl;
      }
      cout << endl;
    }
  }

  //	printf("%lld",f[n][k][k]);
  return 0;
}
