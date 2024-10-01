#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    double ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      ans += 1 / (pow(-1, i + 1) * i);
    }
    printf("%.2lf\n", ans);
  }
  return 0;
}
