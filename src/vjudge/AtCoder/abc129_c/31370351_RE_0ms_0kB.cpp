#include <iostream>
using namespace std;

int n, m;
bool b[10005];
int a[10005];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int x;
    cin >> x;
    b[x] = 1;
    if (((x >= 2) && b[x - 1]) || ((x <= n - 1) && b[x + 1])) {
      cout << 0;
      return 0;
    }
  }
  a[0] = 1;
  for (int i = 0; i <= n; ++i) {
    a[i] %= ((int)1e9 + 7);
    if (!b[i + 1]) {
      a[i + 1] += a[i];
    }
    if (!b[i + 2]) {
      a[i + 2] += a[i];
    }
  }
  cout << a[n];
  return 0;
}
