#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

const double PI = 3.1415926;
double w, h, ans;

int main() {
  while (233) {
    cin >> w >> h;
    if (w == 0 && h == 0) {
      return 0;
    }
    if (w > h) {
      swap(w, h);
    }
    ans = 0;
    if (h >= w * PI + w) {
      ans = max(ans, PI * pow(w / 2.0, 2) * w);
    } else {
      double r = h / (2.0 + 2.0 * PI);
      ans = max(ans, PI * r * r * w);
    }
    double r = w / (2.0 * PI);
    ans = max(ans, PI * r * r * (h - 2.0 * r));
    cout << fixed << setprecision(3) << ans << endl;
  }
}
