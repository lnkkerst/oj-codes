#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 2333333, MOD = 1e9 + 7;

int kmp[MAXN], ans[MAXN];
char a[MAXN], b[MAXN];

signed main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", a + 1);
    int la = strlen(a + 1), j = 0, cnt = 1;
    ans[1] = 1;
    memset(kmp, 0, sizeof(kmp));
    for (int i = 2; i <= la; ++i) {
      while (j && a[i] != a[j + 1]) {
        j = kmp[j];
      }
      if (a[i] == a[j + 1]) {
        ++j;
      }
      kmp[i] = j, ans[i] = ans[j] + 1;
    }
    j = 0;
    for (int i = 2; i <= la; ++i) {
      while (j && a[i] != a[j + 1]) {
        j = kmp[j];
      }
      if (a[i] == a[j + 1]) {
        ++j;
      }
      while (j * 2 > i) {
        j = kmp[j];
      }
      cnt *= ans[j] + 1, cnt %= MOD;
    }
    printf("%lld\n", cnt);
  }
  return 0;
}
