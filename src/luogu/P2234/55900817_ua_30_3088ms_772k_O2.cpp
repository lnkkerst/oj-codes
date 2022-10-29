#include <cmath>
#include <iostream>
using namespace std;

int n, a[32768], ans = 0;

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  ans += a[1];
  for (int i = 2; i <= n; ++i) {
    int t = 1e9;
    for (int j = 1; j < i; ++j) {
      t = min(t, abs(a[i] - a[j]));
    }
    ans += t;
  }
  cout << ans;
  return 0;
}