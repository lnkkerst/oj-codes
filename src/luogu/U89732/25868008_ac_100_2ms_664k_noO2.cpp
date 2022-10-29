#include <bits/stdc++.h>
using namespace std;

bool pd(int a) {
  if (a == 1)
    return 0;
  if (a == 2 || a == 3)
    return 1;
  if (a % 6 != 1 && a % 6 != 5)
    return 0;
  for (int i = 5; i <= sqrt(a); i += 6)
    if (a % i == 0 || a % (i + 2) == 0)
      return 0;
  return 1;
}

int n, k, a[233];
bool b[233];
int ans;

void dfs(int x, int sum, int s) {
  if (x == n + 1 || s == k) {
    if (pd(sum) && s == k)
      ++ans;
    return;
  }
  dfs(x + 1, sum + a[x], s + 1);
  dfs(x + 1, sum, s);
  return;
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  dfs(1, 0, 0);
  cout << ans;
  return 0;
}