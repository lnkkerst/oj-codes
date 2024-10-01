#include <iostream>
#include <queue>
using namespace std;

string str;
int n;
bool fl = 0;
deque<char> a;

int main() {
  cin >> str >> n;
  for (auto i : str) {
    a.push_back(i);
  }
  while (n--) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      fl = !fl;
    } else {
      int pos;
      char ch;
      cin >> pos >> ch;
      if (pos == 1) {
        if (fl) {
          a.push_back(ch);
        } else {
          a.push_front(ch);
        }
      } else {
        if (fl) {
          a.push_front(ch);
        } else {
          a.push_back(ch);
        }
      }
    }
  }
  if (fl) {
    for (auto i = a.begin(); i != a.end(); ++i) {
      cout << *i;
    }
  } else {
    for (auto i : a) {
      cout << i;
    }
  }
  return 0;
}
