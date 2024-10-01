#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int tot = 0, cnt = 0;
  int n, x;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    if (x > 0) {
      tot += x, ++cnt;
    }
  }
  int ans = tot / cnt;
  cout << (ans + (ans * cnt < tot));
  return 0;
}
