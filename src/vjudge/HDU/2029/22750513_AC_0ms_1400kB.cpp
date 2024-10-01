#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

bool pd(string a) {
  int len = (int)a.length();
  string b;
  for (int i = 0; i < len; ++i) {
    b.push_back(a[len - i - 1]);
  }
  if (a == b) {
    return 1;
  }
  return 0;
}

int main() {
  int n;
  string a;
  cin >> n;
  while (n--) {
    cin >> a;
    if (pd(a)) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }
  return 0;
}
