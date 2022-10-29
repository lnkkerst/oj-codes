#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

string a, b;

int main() {
  cin >> a >> b;
  if (a.length() < b.length())
    swap(a, b);
  int l1 = a.length(), l2 = b.length();
  a += a, b += b;
  int size = l2;
  bool fl = 0;
  while (size-- && !fl)
    for (int i = 0; i + size < l2 << 1; ++i)
      if (strstr(a.c_str(), b.substr(i, size).c_str())) {
        fl = 1;
        break;
      }
  cout << size + 1;
  return 0;
}