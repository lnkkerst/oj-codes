#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, r;
    cin >> n >> r;
    int ans = 0;
    int pos = 0;
    while (pos * pos * 2 < r)
      ++pos;
    int e[][2] = {{r, 0},
                  {-r, 0},
                  {0, r},
                  {0, -r},
                  // {pos, pos},
                  // {-pos, -pos},
                  // {pos, -pos},
                  // {-pos, pos}
                  {pos + 1, pos - 1},
                  {-pos - 1, 1 - pos},
                  {-pos - 1, pos - 1},
                  {pos + 1, 1 - pos}};
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        ans += (e[i][0] - e[j][0]) * (e[i][0] - e[j][0]) +
               (e[i][1] - e[j][1]) * (e[i][1] - e[j][1]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}