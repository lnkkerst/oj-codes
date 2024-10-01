#include <bits/stdc++.h>
using namespace std;
vector<int> a, d1, d2;
int main() {
  int tmp;
  while (cin >> tmp) {
    a.push_back(tmp);
  }
  d1.push_back(a.front());
  d2.push_back(a.front());
  for (int i = 1; i < (int)a.size(); ++i) {
    if (d1.back() >= a[i]) {
      d1.push_back(a[i]);
    } else {
      *upper_bound(d1.begin(), d1.end(), a[i], greater<int>()) = a[i];
    }
    if (d2.back() < a[i]) {
      d2.push_back(a[i]);
    } else {
      *lower_bound(d2.begin(), d2.end(), a[i]) = a[i];
    }
  }
  cout << (int)d1.size() << endl << (int)d2.size() << endl;
  return 0;
}
