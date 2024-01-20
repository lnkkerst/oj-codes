#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int ac, ad, bc, bd;
  cin >> ac >> ad >> bc >> bd;
  if (ac + bd < ad + bc) {
    cout << "AB//CD" << endl;
  } else {
    cout << "AB//DC" << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
