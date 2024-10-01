#include <iostream>
using namespace std;

int n, m, ans;
int a[1000010];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int l = 1, r = (int)1e9;
  while (l <= r) {
    int mid = (l + r) / 2;
    int tmp = 0;
    for (int j = 1; j <= n; ++j) {
      tmp += max(0, a[j] - mid);
    }
    if (tmp > m) {
      l = mid;
    } else if (tmp < m) {
      r = mid;
    } else {
      cout << mid;
      return 0;
    }
  }
  cout << l;
  return 0;
}
