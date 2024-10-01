#include <iostream>
#define int long long
using namespace std;

signed main() {
  int x;
  cin >> x;
  int cnt = 1, ans = 0;
  while (x) {
    ans += cnt;
    x >>= 1;
    cnt <<= 1;
  }
  cout << ans;
  return 0;
}
