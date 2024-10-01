#include <iostream>
using namespace std;
int main() {
  int n;
  string a;
  cin >> n >> a;
  for (int i = 0; i < a.length(); i++) {
    a[i] = a[i] + n;
  }
  for (int i = 0; i < a.length(); i++) {
    cout << a[i];
  }
  return 0;
}
