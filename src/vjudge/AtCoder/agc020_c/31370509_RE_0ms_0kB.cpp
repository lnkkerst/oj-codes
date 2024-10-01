#include <iostream>
using namespace std;

bool b[2000 * 2000 + 10];

int main() {
  int n, tot = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    b[x] = 1;
    tot += x;
  }
  int ans = (tot + 1) >> 1;
  while (!b[ans]) {
    ++ans;
  }
  cout << ans;
  return 0;
}
