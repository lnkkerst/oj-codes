#include <iostream>
using namespace std;

double p1x, p2x, p1y, p2y, k, m, a, b, c, d;
int t;

int main() {
  cin >> p1x >> p1y >> p2x >> p2y >> t;
  if (p1y == p2y) {
    while (t--) {
      cin >> a >> b;
      printf("%.9lf %.9lf\n", a, p1y * 2 - b);
    }
  } else if (p1x == p2x) {
    while (t--) {
      cin >> a >> b;
      printf("%.9lf %.9lf\n", p1x * 2 - a, b);
    }
  } else {
    k = (p1y - p2y) / (p1x - p2x);
    m = p1y - k * p1x;
    cout << k << ' ' << m << endl;
    while (t--) {
      cin >> a >> b;
      c = (a + k * b - a * k * k + k * b + 2 * k * m) / (k * k + 1);
      d = a * k + c * k + m * 2.0 - b;
      printf("%.9lf %.9lf\n", c, d);
    }
  }
  return 0;
}
