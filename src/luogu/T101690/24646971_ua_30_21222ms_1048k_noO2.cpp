#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[500001];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int maxi = -99999, maxn = -99999;
    for (int i = l; i <= r; ++i)
      maxi = max(maxi, a[i]);
    for (int i = r; i > l; --i) {
      int maxii = -99999;
      for (int j = l; j < i; ++j)
        if (a[j] > a[i])
          maxii = max(maxii, a[j]);
      maxn = max(maxn, maxii + a[i]);
    }
    printf("%d\n", max(maxi, maxn));
  }
  return 0;
}