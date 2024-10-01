#include <iostream>
using namespace std;
int main() {
  int a[100], s = 0;
  for (int i = 0;; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      break;
    }
    s++;
  }
  for (int i = s - 1; i >= 0; i--) {
    cout << a[i] << " ";
  }
  return 0;
}
