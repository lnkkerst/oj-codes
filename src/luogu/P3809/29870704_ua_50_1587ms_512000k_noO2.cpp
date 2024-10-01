#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

string str;
vector<pair<string, int>> a;

int main() {
  cin >> str;
  for (int i = 0; i < (int)str.length(); ++i) {
    a.push_back(make_pair(str.substr(i), i + 1));
  }
  sort(a.begin(), a.end());
  for (auto i = a.begin(); i != a.end(); ++i) {
    cout << i->second << ' ';
  }
  return 0;
}
