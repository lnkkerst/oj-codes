#include <iostream>
using namespace std;

int main() {
  int h, a, b;
  cin >> h >> a >> b;
  if (b >= a) {
    puts("NO");
    return 0;
  }
  puts("YES");
  int ans = 0, now = 0;
  while (1) {
    now += a;
    ++ans;
    if (now >= h) {
      break;
    }
    now -= b;
  }
  cout << ans << endl;
}
