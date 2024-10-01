#include <iostream>
using namespace std;

int n, a[100010], ans;
bool b[100010];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    if (!b[i]) {
      ++ans;
      b[i] = 1;
      for (int j = i; j <= n; ++j) {
        if (a[j] > a[i]) {
          b[j] = 1;
        }
      }
    }
  }
  cout << ans;
  return 0;
}
