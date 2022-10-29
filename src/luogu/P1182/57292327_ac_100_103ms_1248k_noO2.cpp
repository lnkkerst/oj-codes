#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m, l = 0, r = 0;
  cin >> n >> m;
  vector<int> a;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a.emplace_back(x);
    l = max(l, x);
    r += x;
  }
  while (l <= r) {
    int mid = (l + r) >> 1;
    int tmp = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (tmp + a[i] <= mid) {
        tmp += a[i];
      } else {
        tmp = a[i];
        ++cnt;
      }
    }
    if (cnt < m) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << l;
  return 0;
}