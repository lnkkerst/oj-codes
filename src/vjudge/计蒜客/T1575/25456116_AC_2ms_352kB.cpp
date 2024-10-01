#include <iostream>
using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  if (x > y) {
    cout << n;
    return 0;
  }
  int cnt = 0, xx;
  for (int i = 1; i <= n; ++i) {
    cin >> xx;
    if (xx <= x) {
      ++cnt;
    }
  }
  cout << ((cnt + 1) >> 1);
  return 0;
}
