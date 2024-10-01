#include <cstdio>
using namespace std;
int main() {
  int n;
  double m;
  scanf("%d", &n);
  if (n <= 150 && n >= 0) {
    m = n * 0.4463;
  } else if (n >= 151 && n <= 400) {
    m = 150 * 0.4463 + (n - 150) * 0.4663;
  } else if (n >= 401 && n <= 10000) {
    m = 150 * 0.4463 + 250 * 0.4663 + (n - 400) * 0.5663;
  }
  printf("%.1f", m);
  return 0;
}
