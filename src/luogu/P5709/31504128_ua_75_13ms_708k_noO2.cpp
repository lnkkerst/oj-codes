#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (!b)
    cout << a;
  else
    cout << max(0, a - c / b);
  return 0;
}