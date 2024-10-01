#include <iostream>
using namespace std;

void pross(string a) {
  string b;
  for (int i = (int)a.length() - 1; i >= 0; --i) {
    b.push_back(a[i]);
  }
  cout << b << ' ';
}

int main() {
  string a;
  while (cin >> a) {
    pross(a);
  }
  return 0;
}
