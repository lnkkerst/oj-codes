/*********************************************************************
    $PROGRAM$:
    $COPYRIGHT$:
    $AUTHOR$:
    $DATETIME$: 2024/8/1 14:00:09
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
#include <map>
using namespace std;
const ll maxn = 1000100;
const ll inf = 0x3f3f3f3f3f3f3f3fll;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
map<pair<ll, ll>, ll> mp;
ll a[maxn], n, m, s, cnt, minx, maxx;
ll du[maxn], pd, qi[maxn], vis[maxn];
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

void init() {
  fill(du, du + 10 + n, 0);
  pd = 1;
  cnt = 0;
  mp.clear();
  fill(vis, vis + 10 + n, 0);
}

int main() {
  ll T = read();
  while (T--) {
    init();
    n = read();
    m = read();

    for (int i = 1; i <= m; ++i) {
      ll x, y;
      x = read();
      y = read();
      du[x]++;
      du[y]++;
      mp[{x, y}] = 1;
    }
    for (int i = 1; i <= n; ++i) {
      if (du[i] == n - 1) {
        pd = 0;
      }
      if (du[i] == n - 2) {
        cnt++;
        qi[cnt] = i;
      }
    }
    //		sort(du+1,du+1+n,cmp);
    if (cnt >= 3) {
      pd = 0;
    }
    if (pd == 0) {
      printf("-1\n");
      continue;
    }
    ll q = qi[1];
    if (cnt == 0) {
      q = 1;
    }
    printf("%lld ", q);
    while (q) {
      vis[q] = 1;
      ll tmp = 0;
      for (int i = 1; i <= n; ++i) {
        if (q == i) {
          continue;
        }
        if (vis[i]) {
          continue;
        }
        if (du[i] == n - 2) {
          continue;
        }
        if ((!mp[{q, i}]) && (!mp[{i, q}])) {
          tmp = i;
          break;
        }
        //				cout<<i<<"greg"<<endl;
      }
      if (tmp == 0) {
        break;
      }
      printf("%lld ", tmp);
      q = tmp;
    }
    if (cnt == 2) {
      printf("%lld", qi[2]);
    }
    printf("\n");
  }
  return 0;
}
