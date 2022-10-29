#include <iostream>
using namespace std;

int n;
string str;

int main() {
  cin >> n >> str;
  for (int i = 'z'; i >= 'a'; --i)
    for (int j = 1; j <= 100; ++j)
      for (int k = 0; k < (int)str.size(); ++k)
        if (str[k] == i && (str[k - 1] == i - 1 || str[k + 1] == i - 1))
          str.erase(k--, 1);
  cout << n - (int)str.size();
  return 0;
}