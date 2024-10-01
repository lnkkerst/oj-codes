#include <cmath>
#include <iostream>
using namespace std;

char a[1000010];
int n, b[1000010];

int main() {
  cin >> n >> a + 1;
  int last = n + 1;
  for (int i = n; i >= 1; --i) {
    a[i] -= '0';
    b[i] = last;
    if (b[i] != 1) {
      last = i;
    }
  }
  int mx = log2(n * 2 - 1), ans = 0;
  for (int i = 1; i <= n; ++i) {
    int mul = 1, pos = i;
    for (int j = 1; pos <= n && j <= mx; ++j) {
      mul *= a[pos];
      if (mul > n) {
        break;
      }
      if (mul >= pos - i + 1 && mul <= b[pos] - i) {
        ++ans;
      }
      pos = b[pos];
    }
  }
  cout << ans;
  return 0;
}
