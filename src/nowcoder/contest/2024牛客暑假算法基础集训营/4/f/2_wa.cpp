/*********************************************************************
    $PROGRAM$:
    $COPYRIGHT$:
    $AUTHOR$:
    $DATETIME$: 2024/7/25 14:06:07
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
#define ll __int128_t
#define int __int128_t
using namespace std;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
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

ll check(ll n, ll x) {
  ll da = n * (n - 1) / 2;
  ll xiao = 0;
  if (n % 2 == 0) {
    ll tmp = n / 2;
    xiao = tmp * (tmp + 1) / 2 + tmp * (tmp - 1) / 2;
  } else {
    ll tmp = n / 2;
    xiao = tmp * (tmp + 1);
  }
  if (da - xiao >= x) {
    return 1;
  } else {
    return 0;
  }
}

signed main() {
  ll t = read();
  //	for(int i=6;i<=700;++i){
  //		cout<<i<<" ";
  //		cout<<(i*(i-1)/2)<<" ";
  //		ll tmp=0;
  //		tmp
  //	}
  while (t--) {
    ll x = read();
    ll l = 3, r = 1e12, ans = 0;
    while (l <= r) {
      ll mid = (l + r) >> 1;
      if (check(mid, x)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    printf("%lld\n", (long long)ans);
  }
  return 0;
}
