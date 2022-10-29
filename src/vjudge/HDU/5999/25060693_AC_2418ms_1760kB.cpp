#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int a[100010];

int main() {
  int t;
  scanf("%d", &t);
  for (int k = 1; k <= t; ++k) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
      scanf("%d", &a[i]);
    sort(a + 1, a + n + 1, greater<int>());
    int ans = 0;
    for (int i = 1; i <= n; ++i)
      if (i % 3)
        ans += a[i];
    printf("Case #%d: %d\n", k, ans);
  }
  return 0;
}