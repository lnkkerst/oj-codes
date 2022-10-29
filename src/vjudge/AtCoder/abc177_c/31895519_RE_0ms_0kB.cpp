#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a{n}, b{n};
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  b[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    b[i] = b[i + 1] + a[i];
    b[i] %= 1000000007;
  }
  ll ans = 0;
  for (int i = 0; i < n - 1; ++i) {
    ans += a[i] * b[i + 1];
    ans %= 1000000007;
  }
  cout << ans;
  return 0;
}