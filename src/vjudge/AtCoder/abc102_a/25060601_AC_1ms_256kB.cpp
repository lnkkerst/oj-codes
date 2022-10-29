#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n & 1)
    cout << (n << 1);
  else
    cout << n;
  return 0;
}