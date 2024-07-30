/*********************************************************************
    $PROGRAM$:
    $COPYRIGHT$:
    $AUTHOR$:
    $DATETIME$: 2024/7/18 13:35:08
    $DESCRIPTION$:
*********************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#ifdef Debug
#define D() cerr << __LINE__ << endl;
#else
#define D()
#endif
#define ll long long
#define ull unsigned long long
#define int long long
using namespace std;
const ll maxn = 1000100;
const ll inf = 0x3f3f3f3f3f3f3f3fll;
/*
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
*/
char a[maxn];
ll n, m, s, cnt, minx, maxx, ans;
ll tx, ty, lef[maxn], rig[maxn], abo[maxn], bel[maxn];
map<pair<ll, ll>, ll> mp;
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
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> tx >> ty;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    lef[i] = lef[i - 1];
    rig[i] = rig[i - 1];
    abo[i] = abo[i - 1];
    bel[i] = bel[i - 1];
    if (a[i] == 'A') {
      lef[i]++;
    }
    if (a[i] == 'S') {
      bel[i]++;
    }
    if (a[i] == 'W') {
      abo[i]++;
    }
    if (a[i] == 'D') {
      rig[i]++;
    }
  }

  //	for(int i=1;i<=n;++i){
  //		for(int j=0;j<=i;++j){
  //			if(i==n&&j==n){
  //				continue;
  //			}
  //			ll trig=rig[i]-rig[j];
  //			ll tlef=lef[i]-lef[j];
  //			ll tabo=abo[i]-abo[j];
  //			ll tbel=bel[i]-bel[j];
  //			if(trig-tlef==tx&&tabo-tbel==ty){
  //				ans=ans+n-i+1;
  //			}
  //		}
  //	}
  if (tx == 0 && ty == 0) {
    ans = n * (n + 1) / 2;
    cout << ans;
    return 0;
  }
  for (int i = n; i >= 0; --i) {
    pair<ll, ll> tmp = make_pair(rig[i] - lef[i], abo[i] - bel[i]);
    if (mp.find(tmp) != mp.end()) {
      ans = ans + (n - mp[tmp] + 1);
    }
    pair<ll, ll> res = make_pair(rig[i] - lef[i] - tx, abo[i] - bel[i] - ty);
    if (mp.find(res) == mp.end()) {
      mp[res] = i;
    } else {
      mp[res] = min(mp[res], i);
    }
  }
  cout << ans;
  return 0;
}
