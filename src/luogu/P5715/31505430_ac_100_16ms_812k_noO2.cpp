#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> a;
  for (int i = 1; i <= 3; ++i) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  for (auto i : a)
    cout << i << ' ';
  return 0;
}