#include <iostream>
#define int long long
using namespace std;

int a[500010], n;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int last = 0;
  for (int i = 1; i <= n; i += 2) {
    last += a[i];
  }
  for (int i = 2; i <= n; i += 2) {
    last -= a[i];
  }
  cout << last;
  for (int i = 2; i <= n; ++i) {
    cout << ' ' << (last = a[i - 1] * 2 - last);
  }
  return 0;
}