#include <iostream>
using namespace std;

int n, a[100010], ans = 0;
int sk[100010], top = 0;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n - 1; ++i) {
    cin >> a[i];
    if (a[i] == i)
      sk[++top] = i;
  }
  for (int i = 1; i <= top; ++i, ++ans)
    if (sk[top + 1] == sk[top] + 1)
      ++i;
  cin >> a[n];
  cout << ans + (a[n] == n);
  return 0;
}