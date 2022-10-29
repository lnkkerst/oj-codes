#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    cout << (1 << 30) % x << endl;
  }
  return 0;
}