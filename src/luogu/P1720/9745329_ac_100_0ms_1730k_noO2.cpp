#include <cmath>
#include <cstdio>
using namespace std;
int main() {
  int n;
  scanf("%ld", &n);
  const double N = sqrt(5);
  printf("%.2lf", (pow(((1 + N) / 2), n) - pow(((1 - N) / 2), n)) / N);
  return 0;
}