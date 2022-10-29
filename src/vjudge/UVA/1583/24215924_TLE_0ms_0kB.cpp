#include <iostream>
using namespace std;

int t, n;
bool check(int x, int t) {
  int base = x;
  do {
    base += x % 10;
    x /= 10;
  } while (x);
  if (base == t)
    return 1;
  else
    return 0;
}

int solve(int x) {
  int fl = 0;
  for (int i = 1; i <= x; ++i) {
    if (check(i, x)) {
      fl = i;
      break;
    }
  }
  return fl;
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    int ans = solve(n);
    cout << ans << endl;
  }
  return 0;
}