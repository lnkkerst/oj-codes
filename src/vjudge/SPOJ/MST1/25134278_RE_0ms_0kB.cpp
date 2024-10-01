#include <iostream>
using namespace std;

int f[10000001];

int main() {
  for (int i = 2; i <= 10000000; ++i) {
    f[i] = f[i - 1] + 1;
    if (!(i & 1)) {
      f[i] = min(f[i], f[i >> 1] + 1);
    }
    if (!(i % 3)) {
      f[i] = min(f[i], f[i / 3] + 1);
    }
  }
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    int x;
    cin >> x;
    cout << "Case " << i << ": " << f[x] << endl;
  }
  return 0;
}
