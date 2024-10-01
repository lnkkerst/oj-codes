// #include <iostream>
// #define int long long
// using namespace std;

// signed main() {
//     int t;
//     cin >> t;
//     while(t--) {
//         int x;
//         cin >> x;
//         cout << (x >> 1) * (x - (x >> 1)) << endl;
//     }
//     return 0;
// }

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    int ans = 0;
    while (x != 1) {
      if (x % 3 == 0) {
        x /= 3;
      } else if (x % 2 == 0) {
        x /= 2;
      } else {
        --x;
      }
      ++ans;
    }
    cout << ans << endl;
  }
  return 0;
}
