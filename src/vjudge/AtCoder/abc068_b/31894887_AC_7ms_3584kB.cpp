#include <iostream>
using std::cin;
using std::cout;

int main() {
  int n;
  cin >> n;
  int cnt = 0, ans = 1;
  for (int i = n; i >= 1; --i) {
    int t1 = i, t2 = 0;
    while (t1 != 1 && t1 % 2 == 0) {
      t1 >>= 1;
      ++t2;
    }
    if (t2 > cnt) {
      cnt = t2;
      ans = i;
    }
  }
  cout << ans;
  return 0;
}
