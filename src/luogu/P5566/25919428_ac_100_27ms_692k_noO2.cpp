#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  cin >> n;
  int tmp = n + 1, ans = 0;
  while (tmp > 1)
    ans += tmp & 1, tmp >>= 1;
  cout << ans << endl;
  tmp = n + 1, ans = 0;
  while (tmp > 1) {
    if (tmp == 2)
      ++ans;
    if ((tmp & 3) == 1)
      ans += tmp / 4 * 2 - 1, tmp /= 4, ++tmp;
    else if ((tmp & 3) == 2)
      ans += tmp / 4 * 2, tmp /= 4, ++tmp;
    else if ((tmp & 3) == 3)
      ans += tmp / 4 * 2 + 1, tmp /= 4, ++tmp;
    else
      ans += tmp / 4 * 2, tmp /= 4;
  }
  cout << ans;
  return 0;
}