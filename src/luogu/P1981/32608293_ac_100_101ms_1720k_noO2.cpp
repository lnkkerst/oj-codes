#include <cctype>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

template <typename T> class Mstack {
private:
  vector<T> a;

public:
  Mstack<T>(){};
  ~Mstack<T>(){};
  void pop() { this->a.pop_back(); }
  void push(T a) { this->a.push_back(a); }
  size_t size() const { return (size_t)this->a.size(); }
  bool empty() const { return this->a.empty(); }
  T top() const { return this->a.back(); }
};

int main() {
  stack<int> num;
  stack<char> opt;
  string a;
  cin >> a;
  for (int i = 0; i < (int)a.length(); ++i) {
    if (isdigit(a[i])) {
      int tmp = 0;
      while (isdigit(a[i]))
        tmp *= 10, tmp += a[i] - '0', ++i;
      num.push(tmp % 10000);
      i--;
    } else {
      if (opt.empty())
        opt.push(a[i]);
      else {
        if (a[i] < opt.top())
          opt.push(a[i]);
        else {
          int t1 = num.top();
          num.pop();
          int t2 = num.top();
          num.pop();
          if (opt.top() == '*')
            num.push((t1 * t2) % 10000);
          else
            num.push((t1 + t2) % 10000);
          opt.pop();
          opt.push(a[i]);
        }
      }
    }
  }
  while (!opt.empty()) {
    int t1 = num.top();
    num.pop();
    int t2 = num.top();
    num.pop();
    if (opt.top() == '+')
      num.push((t1 + t2) % 10000);
    else
      num.push((t1 * t2) % 10000);
    opt.pop();
  }
  cout << num.top() % 10000;
  return 0;
}