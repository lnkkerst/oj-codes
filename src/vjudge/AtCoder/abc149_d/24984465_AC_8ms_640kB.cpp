#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char, int> sc;
int n, k, r, s, p, ans = 0;
string ma, pe;

int main() {
  cin >> n >> k >> r >> s >> p >> ma;
  sc['r'] = r, sc['s'] = s, sc['p'] = p;
  for (auto i : ma) {
    if (i == 'r')
      pe.push_back('p');
    else if (i == 's')
      pe.push_back('r');
    else
      pe.push_back('s');
  }
  for (int i = k; i < (int)pe.size(); ++i)
    if (pe[i] == pe[i - k])
      pe[i] = 'f';
  for (auto i : pe)
    ans += sc[i];
  cout << ans;
  return 0;
}