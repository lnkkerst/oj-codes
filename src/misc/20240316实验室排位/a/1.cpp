#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  int cnt = 1e9;
  int a[6];
  for (a[0] = 0; a[0] <= 9; ++a[0]) {
    for (a[1] = 0; a[1] <= 9; ++a[1]) {
      for (a[2] = 0; a[2] <= 9; ++a[2]) {
        for (a[3] = 0; a[3] <= 9; ++a[3]) {
          for (a[4] = 0; a[4] <= 9; ++a[4]) {
            for (a[5] = 0; a[5] <= 9; ++a[5]) {
              if (a[0] + a[1] + a[2] != a[3] + a[4] + a[5]) {
                continue;
              }
              int t = 0;
              for (int i = 0; i < 6; ++i) {
                if (s[i] - '0' != a[i]) {
                  ++t;
                }
              }
              cnt = min(cnt, t);
            }
          }
        }
      }
    }
  }
  cout << cnt << endl;
}
