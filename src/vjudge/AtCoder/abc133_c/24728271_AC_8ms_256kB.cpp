#include <iostream>
#define int long long
using namespace std;

int l, r;

signed main() {
  cin >> l >> r;
  if (l > r)
    swap(l, r);
  if (r - l > 2019) {
    cout << 0;
    return 0;
  }
  int ans = 1000000;
  for (int i = l; i <= r; ++i) {
    for (int j = i + 1; j <= r; ++j) {
      ans = min((i % 2019) * (j % 2019) % 2019, ans);
    }
  }
  cout << ans;
  return 0;
}