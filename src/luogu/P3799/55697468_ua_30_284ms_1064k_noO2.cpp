#include <iostream>
using namespace std;

int n, a[500010], b[5010], ans;

int main() {
  cin >> n;
  int ma = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++b[a[i]];
    ma = max(ma, a[i]);
  }
  for (int i = ma; i >= 1; --i) {
    if (b[i] < 2) {
      continue;
    }
    for (int j = i - 1; j >= (i + 1) / 2; --j) {
      if (j != i - j) {
        ans += ((b[i] * (b[i] - 1)) >> 1) * b[j] * b[i - j];
      } else if (b[j] >= 2) {
        ans += ((b[i] * (b[i] - 1)) >> 1) * ((b[j] * (b[j] - 1)) >> 1);
      }
    }
  }
  cout << ans;
  return 0;
}
