#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a.emplace_back(x);
  }
  deque<int> queMax, queMin;
  vector<int> ansMax, ansMin;
  for (int i = 0; i < k; ++i) {
    while (!queMax.empty() && a[queMax.back()] <= a[i]) {
      queMax.pop_back();
    }
    while (!queMin.empty() && a[queMin.back()] >= a[i]) {
      queMin.pop_back();
    }
    queMax.emplace_back(i);
    queMin.emplace_back(i);
  }
  ansMax.emplace_back(a[queMax.front()]);
  ansMin.emplace_back(a[queMin.front()]);
  for (int i = k; i < n; ++i) {
    while (!queMax.empty() && a[queMax.back()] <= a[i]) {
      queMax.pop_back();
    }
    while (!queMin.empty() && a[queMin.back()] >= a[i]) {
      queMin.pop_back();
    }
    queMax.emplace_back(i);
    queMin.emplace_back(i);
    if (queMin.front() <= i - k) {
      queMin.pop_front();
    }
    if (queMax.front() <= i - k) {
      queMax.pop_front();
    }
    ansMax.emplace_back(a[queMax.front()]);
    ansMin.emplace_back(a[queMin.front()]);
  }
  for (auto i : ansMin) {
    cout << i << ' ';
  }
  cout << endl;
  for (auto i : ansMax) {
    cout << i << ' ';
  }
  return 0;
}