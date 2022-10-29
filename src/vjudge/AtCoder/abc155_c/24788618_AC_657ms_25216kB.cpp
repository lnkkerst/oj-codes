#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

map<string, int> b;
int n, maxn = -1;
string str;

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> str;
    maxn = max(maxn, ++b[str]);
  }
  for (auto i : b) {
    if (i.second == maxn)
      cout << i.first << endl;
  }
  return 0;
}