#include <iostream>
using namespace std;

string sum(const string &a, const string &b) {
  string na = string(a.rbegin(), a.rend());
  string nb = string(b.rbegin(), b.rend());
  int last = 0;
  string ret;
  if (na.size() < nb.size())
    swap(na, nb);
  for (int i = 0; i < (int)nb.size(); ++i)
    ret.push_back((na[i] + nb[i] - 96 + last) % 10 + 48),
        last = (na[i] + nb[i] - 96 + last) / 10;
  for (int i = (int)nb.size(); i < (int)na.size(); ++i)
    ret.push_back((na[i] - 48 + last) % 10 + 48),
        last = (na[i] - 48 + last) / 10;
  if (last)
    ret.push_back(last + 48);
  return string(ret.rbegin(), ret.rend());
}

string mul(const string &a, const string &b) {
  string na = string(a.rbegin(), a.rend());
  string nb = string(b.rbegin(), b.rend());
  string ret;
  ret.resize(na.size() + nb.size() + 1);
  for (int i = 0; i < (int)na.size(); ++i)
    for (int j = 0; j < (int)nb.size(); ++j)
      ret[i + j] += (na[i] - 48) * (nb[j] - 48);
  for (int i = 0; i < (int)ret.size(); ++i)
    ret[i + 1] += ret[i] / 10, ret[i] %= 10;
  while (ret.size() > 1 && !ret.back())
    ret.pop_back();
  for (int i = 0; i < (int)ret.size(); ++i)
    ret[i] += 48;
  return string(ret.rbegin(), ret.rend());
}

int main() {
  int n;
  string ans = "1";
  cin >> n;
  for (int i = 1; i <= n; ++i)
    ans = mul(ans, to_string(i));
  cout << ans;
  return 0;
}