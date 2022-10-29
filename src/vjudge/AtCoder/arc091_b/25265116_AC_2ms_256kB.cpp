#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll n, k, ans = 0;
  cin >> n >> k;
  if (!k) {
    cout << n * n;
    return 0;
  }
  for (int i = k + 1; i <= n; ++i)
    ans += (n / i) * (i - k) + max(n % i - k + 1, 0ll);
  cout << ans;
  return 0;
}