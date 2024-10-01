#include <iostream>
using namespace std;

int main() {
  int x;
  cin >> x;
  (x < 0) && (x = -x);
  int ans = 0, t = x;
  while (t) {
    ans += t & 1;
    t >>= 1;
  }
  cout << ans;
  return 0;
}
