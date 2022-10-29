#include <iostream>
using namespace std;

int n, a[100010], ans = 0;
bool b[100010];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] == i)
      b[i] = 1;
  }
  for (int i = 1; i <= n - 1; ++i)
    if (b[i])
      ++ans, b[i + 1] = 0;
  cout << ans + b[n];
  return 0;
}