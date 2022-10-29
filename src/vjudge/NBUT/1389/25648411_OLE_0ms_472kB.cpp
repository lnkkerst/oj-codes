#include <iostream>
using namespace std;

int main() {
  unsigned long long n;
  while (cin >> n)
    cout << (1ull << n) << endl;
  return 0;
}