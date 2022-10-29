#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int x;
  cin >> x;
  cout << (x * 5 < (x * 3 + 11) ? "Local" : "Luogu");
  return 0;
}