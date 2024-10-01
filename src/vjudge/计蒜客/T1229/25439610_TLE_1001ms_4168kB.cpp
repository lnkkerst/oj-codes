#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  map<int, int> a;
  map<int, bool> b;
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
