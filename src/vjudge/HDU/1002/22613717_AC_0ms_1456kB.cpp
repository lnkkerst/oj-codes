#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

char a[2333333], b[2333333], c[2333333];
int t;
int na[2333333], nb[2333333];

string sum(string a, string b) {
  string ret;
  vector<int> na, nb;
  int la = a.size(), lb = b.size();
  int lmax = max(la, lb);
  for (int i = 0; i <= lmax; ++i) {
    na.push_back(0), nb.push_back(0);
  }
  for (int i = 0; i < la; ++i) {
    na[la - i - 1] = a[i] - '0';
  }
  for (int i = 0; i < lb; ++i) {
    nb[lb - i - 1] = b[i] - '0';
  }
  for (int i = 0; i < lmax; ++i) {
    na[i] += nb[i], na[i + 1] += na[i] / 10, na[i] = na[i] % 10;
  }
  if (na[lmax]) {
    ++lmax;
  }
  while (!na[lmax]) {
    --lmax;
  }
  for (int i = lmax; i >= 0; --i) {
    ret += na[i] + '0';
  }
  return ret;
}

int main() {
  string a, b;
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cin >> a >> b;
    string ans = sum(a, b);
    cout << "Case " << i << ":\n";
    cout << a << " + " << b << " = " << (!ans.length() ? "0" : ans) << endl;
    if (i != t) {
      cout << endl;
    }
  }
  return 0;
}
