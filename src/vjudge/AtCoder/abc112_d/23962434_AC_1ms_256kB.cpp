#include <algorithm>
#include <iostream>
using namespace std;

int n, m, ans = 1;

int main() {
  cin >> n >> m;
  for (int i = 1; i * i <= m; ++i) {
    if (!(m % i)) {
      if (m / i >= n) {
        ans = max(ans, i);
      }
      if (i >= n) {
        ans = max(ans, m / i);
      }
    }
  }
  cout << ans;
  return 0;
}
