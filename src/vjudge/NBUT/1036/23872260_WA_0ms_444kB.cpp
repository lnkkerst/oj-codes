#include <algorithm>
#include <cmath>
#include <cstdio>

const double PI = 3.1415926;
double w, h, ans;

int main() {
  while (233) {
    scanf("%lf%lf", &w, &h);
    if (w == 0 && h == 0) {
      return 0;
    }
    if (w > h) {
      std::swap(w, h);
    }
    ans = 0;
    if (h >= w * PI + w) {
      ans = std::max(ans, PI * (w / 2.0) * (w / 2.0) * w);
    } else {
      ans = std::max(ans,
                     PI * w * (h / (2.0 + 2.0 * PI)) * (h / (2.0 + 2.0 * PI)));
    }
    printf("%.3lf\n", std::max(ans, PI * (w / (2.0 * PI)) * (w / (2.0 * PI))
                                      * (h - 2.0 * (w / (2.0 * PI)))));
  }
}
