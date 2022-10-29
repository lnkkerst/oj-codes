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
  if (x == k) {
    if (pd(sum))
      ++ans;
    return;
  }
  for (int i = s; i < n; ++i) {
    if (!b[i]) {
      b[i] = 1;
      dfs(x + 1, sum + a[i], s + 1);
      b[i] = 0;
    }
  }
  return;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  dfs(0, 0, 0);
  cout << ans << endl;
  return 0;
}