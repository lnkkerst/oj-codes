#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node {
  int l, r;
} a[1001];

int n;

bool cmp(Node a, Node b) {
  if (a.l == b.l)
    return a.r < b.r;
  return a.l < b.l;
}

unsigned main() {
  cin >> n >> a[0].l >> a[0].r;
  for (int i = 1; i <= n; ++i)
    cin >> a[i].l >> a[i].r;
  sort(a + 1, a + n + 1, cmp);
  int ans = -1, sum = a[0].l;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, sum / a[i].r);
    sum *= a[i].l;
  }
  cout << ans;
  return 0;
}