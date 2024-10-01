#include <cstdio>
using namespace std;
int main() {
  int k, a, b, c;
  bool flag = 0;
  scanf("%ld", &k);
  for (int i = 10000; i <= 30000; i++) {
    a = i / 100, b = i / 10 % 1000, c = i % 1000;
    if (a % k == 0 && b % k == 0 && c % k == 0) {
      flag = 1;
      printf("%ld\n", i);
    }
  }
  if (flag == 0) {
    printf("No");
  }
  return 0;
}
