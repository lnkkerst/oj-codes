#include <iostream>
using namespace std;

int minn = (int)1e9 + 7, n, x, ans = 0;

int main() {
  cin >> n;
  while (n--) {
    cin >> x;
    if (x < minn) {
      ++ans;
    }
    minn = min(minn, x);
  }
  cout << ans;
  return 0;
}
