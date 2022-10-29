#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

string sum(string a, string b) {
  string ret;
  vector<int> na, nb;
  int la = a.size(), lb = b.size();
  int lmax = max(la, lb);
  for (int i = 0; i <= lmax; ++i)
    na.push_back(0), nb.push_back(0);
  for (int i = 0; i < la; ++i)
    na[la - i - 1] = a[i] - '0';
  for (int i = 0; i < lb; ++i)
    nb[lb - i - 1] = b[i] - '0';
  for (int i = 0; i < lmax; ++i)
    na[i] += nb[i], na[i + 1] += na[i] / 10, na[i] = na[i] % 10;
  if (na[lmax])
    ++lmax;
  for (int i = lmax - 1; i >= 0; --i)
    ret += na[i] + '0';
  return ret;
}

int main() {
  string x, n;
  cin >> n;
  x = n;
  while (1) {
    if (*max_element(x.begin(), x.end()) <= '1') {
      cout << x;
      return 0;
    }
    x = sum(x, n);
  }
  return 0;
}