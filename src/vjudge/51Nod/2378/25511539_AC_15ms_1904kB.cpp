#include <iostream>
#define int long long
using namespace std;

bool pd(int a) {
  if (a == 1)
    return 0;
  if (a == 2 || a == 3)
    return 1;
  if (a % 6 != 1 && a % 6 != 5)
    return 0;
  for (int i = 5; i * i <= a; i += 6)
    if (a % i == 0 || a % (i + 2) == 0)
      return 0;
  return 1;
}

signed main() {
  int x;
  cin >> x;
  while (1) {
    if (pd(x)) {
      cout << x;
      return 0;
    }
    --x;
  }
  return 0;
}