// luogu-judger-enable-o2
#include <iostream>
#define ll long long
using namespace std;
const int MAXN = 100001;
int main() {
  ll n, m, a[MAXN] = {0}, ans[MAXN] = {0}, t = 0, i, j, x, y;
  char event;
  cin >> n >> m;
  for (i = 1; i <= n; i++)
    cin >> a[i];
  for (i = 1; i <= m; i++) {
    cin >> event;
    switch (event) {
    case 'Q':
      t++;
      for (j = 1; j <= n; j++)
        ans[t] += a[j];
      break;
    case 'D':
      cin >> x;
      a[x] = 0;
      break;
    case 'C':
      cin >> x >> y;
      a[x] -= y;
      break;
    case 'I':
      cin >> x >> y;
      a[x] = y;
      if (x > n)
        n = x;
      break;
    }
  }
  for (i = 1; i <= t; i++)
    cout << ans[i] << endl;
  return 0;
}