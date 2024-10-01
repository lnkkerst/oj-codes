#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m, 0);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : a) {
    *min_element(b.begin(), b.end()) += i;
  }
  cout << *max_element(b.begin(), b.end());
  return 0;
}
