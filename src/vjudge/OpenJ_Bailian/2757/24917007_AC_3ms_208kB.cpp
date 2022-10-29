#include <iostream>
using namespace std;

int a[10001], ans[10001], n, len = 1;

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  ans[1] = a[1];
  for (int i = 2; i <= n; ++i)
    if (ans[len] < a[i])
      ans[++len] = a[i];
    else
      *lower_bound(ans + 1, ans + len + 1, a[i]) = a[i];
  cout << len;
  return 0;
}