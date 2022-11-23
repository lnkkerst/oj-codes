#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int n;
  cin >> n;
  unordered_map<int, int> b;
  while (n--) {
    int x;
    cin >> x;
    cout << ++b[x] << ' ';
  }
  return 0;
}
