#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  string n;
  cin >> n;
  cout << (char)*max_element(n.begin(), n.end());
  return 0;
}