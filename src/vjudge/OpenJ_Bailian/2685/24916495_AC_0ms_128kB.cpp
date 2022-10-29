#include <cmath>
#include <iostream>
using namespace std;

bool pd(int x) {
  int tmp = 0, ori = x;
  while (x) {
    int t = x % 10;
    tmp += t * t * t;
    x /= 10;
  }
  return ori == tmp;
}

int main() {
  for (int i = 100; i < 1000; ++i)
    if (pd(i))
      cout << i << endl;
  return 0;
}