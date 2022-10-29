#include <iostream>
using namespace std;

#define int long long

int n, m, ans;
int a[1000010];

signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int l = 1, r = (int)1e9;
  while (l <= r) {
    int mid = (l + r) / 2;
    int tmp = 0;
    for (int j = 1; j <= n; ++j) {
      tmp += max(0ll, a[j] - mid);
    }
    if (tmp > m) {
      l = mid + 1;
    } else if (tmp < m) {
      r = mid - 1;
    } else {
      cout << mid;
      return 0;
    }
  }
  cout << l - 1;
  return 0;
}