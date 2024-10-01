#include <iostream>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int ans = n / (a + b);
  n %= a + b;
  ans *= a;
  ans += min(a, n);
  cout << ans;
  return 0;
}
