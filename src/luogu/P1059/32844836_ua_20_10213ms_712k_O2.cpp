#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> a;
  int n;
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  while (!is_sorted(a.begin(), a.end(), less<int>()))
    random_shuffle(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  cout << a.size() << endl;
  for (auto i : a)
    cout << i << ' ';
  return 0;
}