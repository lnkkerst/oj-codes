#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int x;
  int a = !(x & 1);
  int b = x >= 4 && x <= 12;
  printf("%d %d %d %d", a && b, a || b, (a && !b || !a && b), !a && !b);
  return 0;
}