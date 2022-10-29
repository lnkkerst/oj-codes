#include <bits/stdc++.h>
#define MOD 50
using namespace std;

int a[50001];
int n, m;
unordered_map<int, int> b[50001];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    for (int j = i; j <= n; j++)
      ++b[j][a[i]];
  }
  while (m--) {
    int l, r, l1, r1;
    scanf("%d%d%d%d", &l, &r, &l1, &r1);
    int ans = 0;
    for (int i = l; i <= r; ++i)
      ans += b[r1][a[i]] - b[l1 - 1][a[i]];
    printf("%d\n", ans);
  }
  return 0;
}