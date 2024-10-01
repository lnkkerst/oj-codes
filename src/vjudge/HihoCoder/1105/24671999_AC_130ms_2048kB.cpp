#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> a;
int n;

int main() {
  cin >> n;
  while (n--) {
    char opt;
    cin >> opt;
    if (opt == 'A') {
      int x;
      cin >> x;
      a.push(x);
    } else {
      cout << a.top() << endl;
      a.pop();
    }
  }
  return 0;
}
