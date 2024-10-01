#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    cout << x * (9 * x - 7) / 2 + 1 << endl;
  }
  return 0;
}
