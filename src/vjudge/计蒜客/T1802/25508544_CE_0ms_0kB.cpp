//
// Created by lnkkerst on 2020/4/27/027.
//

#include <iostream>
using namespace std;

bool solve(int x, int b) {
  string s;
  int t = x;
  while (t) {
    s.push_back(t % b);
    t /= b;
  }
  string re = s;
  reverse(re.begin(), re.end());
  return re == s;
}

int main() {
  int x;
  cin >> x;
  for (int i = 1; i <= 300; ++i) {
    if (solve(i * i, x)) {
      cout << i << ' ' << i * i << endl;
    }
  }
  return 0;
}
