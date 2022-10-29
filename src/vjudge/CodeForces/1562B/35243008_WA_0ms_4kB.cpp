#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

bool isPrime(int x) {
  if (x == 1)
    return false;
  if (x == 2)
    return true;
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0)
      return false;
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int k;
    string s;
    cin >> k >> s;
    vector<int> a;
    for (auto i : s) {
      a.emplace_back(i - '0');
    }
    bool fl = false;
    for (auto i : a) {
      if (!isPrime(i)) {
        fl = true;
        cout << 1 << endl << i << endl;
        break;
      }
    }
    if (fl)
      continue;
    unordered_set<int> b;
    for (auto i : a) {
      if (b.find(i) != b.end()) {
        cout << 2 << endl << i << endl;
        fl = true;
        break;
      }
    }
    if (fl)
      continue;
    for (auto i = a.begin(); i != a.end(); ++i) {
      if (i != a.begin() && (*i == 2 || *i == 5)) {
        cout << 2 << endl << a.front() << *i << endl;
        fl = true;
        break;
      }
    }
    if (fl)
      continue;
    bool fl3 = false, fl7 = false;
    for (auto i = a.begin() + 1; i != a.end(); ++i) {
      if (*i == 3) {
        fl3 = true;
      }
      if (*i == 7) {
        fl7 = true;
      }
    }
    if (fl3) {
      for (int i = 0; i < a.size(); ++i) {
        if (a[i] != 3 && !isPrime(a[i] * 10 + 3)) {
          fl = 0;
          cout << 2 << endl << a[i] << 3 << endl;
          break;
        }
      }
    }
    if (fl)
      continue;
    if (fl7) {
      for (int i = 0; i < a.size(); ++i) {
        if (a[i] != 7 && !isPrime(a[i] * 10 + 7)) {
          fl = 0;
          cout << 2 << endl << a[i] << 7 << endl;
          break;
        }
      }
    }
    if (fl)
      continue;
  }
}