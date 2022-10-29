//
// Created by lnkkerst on 2020/4/27/027.
//

#include <algorithm>
#include <iostream>
#define int long long
using namespace std;

bool pd(int x, int b) {
  string s;
  while (x) {
    s.push_back(x % b + '0');
    x /= b;
  }
  reverse(s.begin(), s.end());
  //    while(s.back() == '0') s.pop_back();
  string re = s;
  reverse(re.begin(), re.end());
  //    cout << s << ' ' << re << endl;
  return re == s;
}

signed main() {
  int x;
  cin >> x;
  for (int i = 1; i <= 300; ++i)
    if (pd(i * i, x))
      cout << i << ' ' << i * i << endl;
  return 0;
}