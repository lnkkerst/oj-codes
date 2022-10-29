#include <bits/stdc++.h>
using namespace std;

int n, a[300010];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  sort(a + 1, a + n + 1, greater<int>());
  double ans = a[1] * a[1];
  int sum = a[1];
  for (int i = 2; i <= n; ++i) {
    sum += a[i];
    double tmp = (double)(sum * sum) / (double)i;
    if (tmp > ans)
      ans = tmp;
    else
      break;
  }
  cout << ans;
}