#include <algorithm>
#include <iostream>
using namespace std;

int a[200010], b[200010], n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(a + 1, a + n + 1);
  int mid = n / 2 + 1;
  for (int i = 1; i <= n; ++i) {
    if (b[i] < a[mid]) {
      cout << a[mid];
    } else {
      cout << a[mid - 1];
    }
    cout << endl;
  }
  return 0;
}
