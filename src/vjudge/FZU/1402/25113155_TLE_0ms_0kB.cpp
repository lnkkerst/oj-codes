#include <iostream>
#define int long long
using namespace std;

int a[11], b[11];

signed main() {
  int n;
  while (cin >> n) {
    for (int i = 1; i <= n; ++i)
      cin >> a[i] >> b[i];
    for (int i = 1; i <= 100000000; ++i) {
      bool fl = 1;
      for (int j = 1; j <= n; ++j) {
        if (i % a[j] != b[j]) {
          fl = 0;
          break;
        }
      }
      if (fl) {
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}