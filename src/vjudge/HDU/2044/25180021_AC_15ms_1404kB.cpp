#include <cstring>
#include <iostream>
#define int long long
using namespace std;

signed main() {
  int t, f[60];
  cin >> t;
  while (t--) {
    memset(f, 0, sizeof f);
    int a, b;
    cin >> a >> b;
    f[a + 1] = f[a + 2] = 1;
    for (int i = a; i <= b; ++i)
      f[i + 1] += f[i], f[i + 2] += f[i];
    cout << f[b] << endl;
  }
  return 0;
}