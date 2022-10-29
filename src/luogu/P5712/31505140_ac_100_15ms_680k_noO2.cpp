#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int x;
  cin >> x;
  if (x <= 1)
    printf("Today, I ate %d apple.", x);
  else
    printf("Today, I ate %d apples.", x);
  return 0;
}