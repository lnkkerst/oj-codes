#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[500001];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int maxi = *max_element(a + l + 1, a + r + 1), maxn = -99999999;
    for (int i = r; i > l; --i) {
      int maxii = *max_element(&a[l], &a[i]);
      if (maxii > a[i]) {
        maxn = max(maxn, maxii + a[i]);
      }
    }
    printf("%d\n", max(maxi, maxn));
  }
  return 0;
}
