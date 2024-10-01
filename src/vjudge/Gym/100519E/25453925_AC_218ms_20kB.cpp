#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define int long long
using namespace std;

int n, d;
int ansk, ansx;

void pd(int x) {
  if (x < 2) {
    return;
  }
  int t = n, len = 0;
  while (t) {
    if (t % x != d) {
      break;
    }
    ++len;
    t /= x;
  }
  if (((len == ansx) && (x < ansk)) || len > ansx) {
    ansx = len;
    ansk = x;
  }
}

signed main() {
  cin >> n >> d;
  for (int i = 1; i * i <= (n - d); ++i) {
    if ((n - d) % i == 0) {
      pd(i);
      pd((n - d) / i);
    }
  }
  if (ansx) {
    cout << ansk << ' ' << ansx;
  } else if (n == d) {
    cout << max(n + 1, 2LL) << " 1";
  } else {
    cout << "2 0";
  }
  return 0;
}
