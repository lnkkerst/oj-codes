/*********************************************************************
    $PROGRAM$:
    $COPYRIGHT$:
    $AUTHOR$:
    $DATETIME$: 2023/10/22 13:40:45
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
struct P {
  ll hp, ach;
} a[17], b[17], c[17], d[17];
ll nn, mm, s, cnt, minx, maxx, ji[100];
double ans1, ans2, ans3;
ll ans3z, ans3m, ans2z, ans2m, ans1z, ans1m;
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

void dfs(ll n, ll m, ll fz, ll fm, ll z, double num) {
  if (z == 1) {
    ll mach = inf, pd = 0, minn = inf;
    for (int i = 1; i <= nn; ++i) {
      if (a[i].hp <= 0) {
        continue;
      }
      if (minn > ji[i]) {
        pd = i;
        minn = ji[i];
        mach = a[i].ach;
      }
    }
    ji[pd]++;
    for (int i = 1; i <= mm; ++i) {
      if (b[i].hp <= 0) {
        continue;
      }
      b[i].hp -= mach;
      a[pd].hp -= b[i].ach;
      ll fz2, fm2;
      fz2 = fz;
      fm2 = m * fm;
      double num2 = num / (double)m;
      if (b[i].hp <= 0) {
        m--;
      }
      if (a[pd].hp <= 0) {
        n--;
      }
      if (n == 0 && m == 0) {
        ans3 += num2;
        if (b[i].hp <= 0) {
          m++;
        }
        if (a[pd].hp <= 0) {
          n++;
        }
        b[i].hp += mach;
        a[pd].hp += b[i].ach;
        continue;
      }
      if (n == 0 && m > 0) {
        ans2 += num2;
        if (b[i].hp <= 0) {
          m++;
        }
        if (a[pd].hp <= 0) {
          n++;
        }
        b[i].hp += mach;
        a[pd].hp += b[i].ach;
        continue;
      }
      if (n > 0 && m == 0) {

        ans1 += num2;
        if (b[i].hp <= 0) {
          m++;
        }
        if (a[pd].hp <= 0) {
          n++;
        }
        b[i].hp += mach;
        a[pd].hp += b[i].ach;
        continue;
      }
      //				if(n>0&&m>0){
      //
      //					if(n>m){
      //						dfs(n,m,fz2,fm2,1,num2);
      //					}
      //					if(m>n){
      //						dfs(n,m,fz2,fm2,2,num2);
      //					}
      //					if(n==m){
      //						dfs(n,m,fz2,fm2*2,1,num2/(double)2.0);
      //						dfs(n,m,fz2,fm2*2,2,num2/(double)2.0);
      //					}
      //					if(b[i].hp<=0){
      //				m++;
      //			}
      //			if(a[pd].hp<=0){
      //				n++;
      //			}
      //					b[i].hp+=mach;
      //					a[pd].hp+=b[i].ach;
      //				}
    }
    ji[pd]--;
    mach = inf;
    pd = 0;
    minn = inf;
    for (int i = 1; i <= mm; ++i) {
      if (b[i].hp <= 0) {
        continue;
      }
      if (ji[i] < minn) {
        minn = ji[i];
        pd = i;
        mach = b[i].ach;
      }
    }
    ji[pd]++;
    for (int i = 1; i <= nn; ++i) {

      if (a[i].hp <= 0) {
        continue;
      }
      a[i].hp -= mach;
      b[pd].hp -= a[i].ach;
      ll fz2, fm2;
      fz2 = fz;
      fm2 = n * fm;
      double num2 = num / (double)n;
      if (b[pd].hp <= 0) {
        m--;
      }
      if (a[i].hp <= 0) {
        n--;
      }
      if (n == 0 && m == 0) {
        ans3 += num2;
        if (b[pd].hp <= 0) {
          m++;
        }
        if (a[i].hp <= 0) {
          n++;
        }
        a[i].hp += mach;
        b[pd].hp += a[i].ach;
        continue;
      }
      if (n == 0 && m > 0) {

        ans2 += num2;
        if (b[pd].hp <= 0) {
          m++;
        }
        if (a[i].hp <= 0) {
          n++;
        }
        a[i].hp += mach;
        b[pd].hp += a[i].ach;
        continue;
      }
      if (n > 0 && m == 0) {
        ans1 += num2;
        if (b[pd].hp <= 0) {
          m++;
        }
        if (a[i].hp <= 0) {
          n++;
        }
        a[i].hp += mach;
        b[pd].hp += a[i].ach;
        continue;
      }
      if (n > 0 && m > 0) {

        if (n > m) {
          dfs(n, m, fz2, fm2, 1, num2);
        }
        if (m > n) {
          dfs(n, m, fz2, fm2, 2, num2);
        }
        if (n == m) {
          dfs(n, m, fz2, fm2 * 2, 1, num2 / (double)2);
          dfs(n, m, fz2, fm2 * 2, 2, num2 / (double)2);
        }
        if (b[pd].hp <= 0) {
          m++;
        }
        if (a[i].hp <= 0) {
          n++;
        }
        a[i].hp += mach;
        b[pd].hp += a[i].ach;
      }
      //			}
    }
    ji[pd]--;
  }

  if (z == 2) {
    ll mach = inf, pd = 0, minn = inf;
    for (int i = 1; i <= mm; ++i) {
      if (b[i].hp <= 0) {
        continue;
      }
      if (ji[i] < minn) {
        minn = ji[i];
        pd = i;
        mach = b[i].ach;
      }
    }
    ji[pd]++;
    for (int i = 1; i <= nn; ++i) {

      if (a[i].hp <= 0) {
        continue;
      }
      a[i].hp -= mach;
      b[pd].hp -= a[i].ach;
      ll fz2, fm2;
      fz2 = fz;
      fm2 = n * fm;
      double num2 = num / (double)n;
      if (b[pd].hp <= 0) {
        m--;
      }
      if (a[i].hp <= 0) {
        n--;
      }
      if (n == 0 && m == 0) {
        ans3 += num2;
        if (b[pd].hp <= 0) {
          m++;
        }
        if (a[i].hp <= 0) {
          n++;
        }
        a[i].hp += mach;
        b[pd].hp += a[i].ach;
        continue;
      }
      if (n == 0 && m > 0) {

        ans2 += num2;
        if (b[pd].hp <= 0) {
          m++;
        }
        if (a[i].hp <= 0) {
          n++;
        }
        a[i].hp += mach;
        b[pd].hp += a[i].ach;
        continue;
      }
      if (n > 0 && m == 0) {
        ans1 += num2;
        if (b[pd].hp <= 0) {
          m++;
        }
        if (a[i].hp <= 0) {
          n++;
        }
        a[i].hp += mach;
        b[pd].hp += a[i].ach;
        continue;
      }
      //				if(n>0&&m>0){
      //
      //					if(n>m){
      //						dfs(n,m,fz2,fm2,1,num2);
      //					}
      //					if(m>n){
      //						dfs(n,m,fz2,fm2,2,num2);
      //					}
      //					if(n==m){
      //						dfs(n,m,fz2,fm2*2,1,num2/(double)2);
      //						dfs(n,m,fz2,fm2*2,2,num2/(double)2);
      //					}
      //					if(b[pd].hp<=0){
      //				m++;
      //			}
      //			if(a[i].hp<=0){
      //				n++;
      //			}
      //					a[i].hp+=mach;
      //					b[pd].hp+=a[i].ach;
      //				}
      //			}
    }
    ji[pd]--;
    mach = inf;
    pd = 0;
    minn = inf;
    for (int i = 1; i <= nn; ++i) {
      if (a[i].hp <= 0) {
        continue;
      }
      if (minn > ji[i]) {
        pd = i;
        minn = ji[i];
        mach = a[i].ach;
      }
    }
    ji[pd]++;
    for (int i = 1; i <= mm; ++i) {
      if (b[i].hp <= 0) {
        continue;
      }
      b[i].hp -= mach;
      a[pd].hp -= b[i].ach;
      ll fz2, fm2;
      fz2 = fz;
      fm2 = m * fm;
      double num2 = num / (double)m;
      if (b[i].hp <= 0) {
        m--;
      }
      if (a[pd].hp <= 0) {
        n--;
      }
      if (n == 0 && m == 0) {
        ans3 += num2;
        if (b[i].hp <= 0) {
          m++;
        }
        if (a[pd].hp <= 0) {
          n++;
        }
        b[i].hp += mach;
        a[pd].hp += b[i].ach;
        continue;
      }
      if (n == 0 && m > 0) {
        ans2 += num2;
        if (b[i].hp <= 0) {
          m++;
        }
        if (a[pd].hp <= 0) {
          n++;
        }
        b[i].hp += mach;
        a[pd].hp += b[i].ach;
        continue;
      }
      if (n > 0 && m == 0) {

        ans1 += num2;
        if (b[i].hp <= 0) {
          m++;
        }
        if (a[pd].hp <= 0) {
          n++;
        }
        b[i].hp += mach;
        a[pd].hp += b[i].ach;
        continue;
      }
      if (n > 0 && m > 0) {

        if (n > m) {
          dfs(n, m, fz2, fm2, 1, num2);
        }
        if (m > n) {
          dfs(n, m, fz2, fm2, 2, num2);
        }
        if (n == m) {
          dfs(n, m, fz2, fm2 * 2, 1, num2 / (double)2.0);
          dfs(n, m, fz2, fm2 * 2, 2, num2 / (double)2.0);
        }
        if (b[i].hp <= 0) {
          m++;
        }
        if (a[pd].hp <= 0) {
          n++;
        }
        b[i].hp += mach;
        a[pd].hp += b[i].ach;
      }
    }
    ji[pd]--;
  }
}

bool cmp(P x, P y) { return x.ach < y.ach; }

int main() {
  nn = read();
  mm = read();
  for (int i = 1; i <= nn; ++i) {
    a[i].ach = read();
    a[i].hp = a[i].ach;
  }
  for (int i = 1; i <= mm; ++i) {
    b[i].ach = read();
    b[i].hp = b[i].ach;
  }

  if (nn > mm) {
    dfs(nn, mm, 1, 1, 1, 1.0);
  } else if (mm > nn) {
    dfs(nn, mm, 1, 1, 2, 1.0);
  } else {
    dfs(nn, mm, 1, 2, 1, 1.0);
    dfs(nn, mm, 1, 2, 2, 1.0);
  }
  printf("%lf\n%lf\n%lf", ans1, ans2, ans3);
  return 0;
}
