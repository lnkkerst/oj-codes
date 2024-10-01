#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    cout << (x / 2020 >= x % 2020 ? "YES" : "NO") << endl;
  }
  return 0;
}
