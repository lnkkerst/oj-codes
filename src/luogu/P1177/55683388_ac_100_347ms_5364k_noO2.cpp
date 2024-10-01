#include <iostream>
#include <map>
using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> a;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    ++a[x];
  }
  for (auto i : a) {
    for (int j = 1; j <= i.second; ++j) {
      cout << i.first << ' ';
    }
  }
  return 0;
}
