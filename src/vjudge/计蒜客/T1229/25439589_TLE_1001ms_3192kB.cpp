#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int n;
  cin >> n;
  unordered_map<int, int> a;
  unordered_map<int, bool> b;
  while (n--) {
    string opt;
    int x;
    cin >> opt >> x;
    if (opt == "add") {
      ++a[x];
      cout << a[x] << endl;
      b[x] = 1;
    }
    if (opt == "ask") {
      cout << b[x] << ' ' << a[x] << endl;
    }
    if (opt == "del") {
      cout << a[x] << endl;
      a[x] = 0;
    }
  }
  return 0;
}
