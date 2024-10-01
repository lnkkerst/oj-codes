#include <cstring>
#include <iostream>
using namespace std;

int main() {
  int t, f[51];
  cin >> t;
  while (t--) {
    memset(f, 0, sizeof f);
    int a, b;
    cin >> a >> b;
    f[a] = 1;
    for (int i = a + 1; i <= b; ++i) {
      f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[b] << endl;
  }
  return 0;
}
