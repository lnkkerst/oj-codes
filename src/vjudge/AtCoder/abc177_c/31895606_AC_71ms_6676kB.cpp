#include <iostream>
using namespace std;
typedef long long ll;

ll a[200000 + 5], b[200000 + 5];
ll n;

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  b[n] = a[n];
  for (int i = n - 1; i >= 1; --i) {
    b[i] = b[i + 1] + a[i];
    b[i] %= 1000000007ll;
  }
  ll ans = 0;
  for (int i = 1; i <= n - 1; ++i) {
    ans += a[i] * b[i + 1];
    ans %= 1000000007ll;
  }
  cout << ans;
  return 0;
}