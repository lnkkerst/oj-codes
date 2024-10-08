#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  while (233) {
    int n;
    cin >> n;
    if (!n) {
      return 0;
    }
    vector<pair<int, int>> a;
    for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      a.push_back(make_pair(abs(x), x));
    }
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    for (auto i : a) {
      cout << i.second << ' ';
    }
    cout << endl;
  }
  return 0;
}
