#pragma GCC optimize(2)
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
long long lob(long long k) {
  return k & (-k);
}
#define int long long
long long n, m;
long long p[6000000], ans[3];
long long a[3][1000000], t[3][8000000], fl;
char s[1000000];
signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    int x = n - p[i] + 1;
    while (x <= n) {
      t[0][x] += 1;
      x += lob(x);
    }
    int as = 0;
    x = n - p[i] + 1;
    while (x) {
      a[0][p[i]] += t[0][x];
      x -= lob(x);
    }
    a[0][p[i]]--;
    ans[0] += a[0][p[i]];
  }
  for (int i = n; i >= 1; --i) {
    int x = n - p[i] + 1;
    while (x <= n) {
      t[1][x] += 1;
      x += lob(x);
    }
    int as = 0;
    x = n - p[i] + 1;
    while (x) {
      a[1][p[i]] += t[1][x];
      x -= lob(x);
    }
    a[1][p[i]]--;
    ans[1] += a[1][p[i]];
  }
  //    for(int i=1;i<=5;++i){
  //        cout<<a[0][i]<<' ';
  //    }cout<<endl;
  cin >> s;
  cout << ans[0] << endl;
  int t = 0;
  for (int k = 1; k <= m; ++k) {
    if (s[k - 1] == 'S') {
      if (fl == 0) {
        ++t;
        if (t == n + 1) {
          t -= n;
        }
      } else {
        --t;
        if (t == 0) {
          t = n;
        }
      }
      ans[fl] = ans[fl] + 1 + n - 2 * p[t];
      ans[fl ^ 1] = ans[fl ^ 1] - 1 - n + 2 * p[t];

      cout << ans[fl] % 10;
    } else {
      fl = fl ^ 1;
      cout << ans[fl] % 10;
      if (fl == 1) {
        ++t;
      } else {
        --t;
      }
    }
  }
  return 0;
}
