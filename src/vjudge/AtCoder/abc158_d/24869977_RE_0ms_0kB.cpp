#include <cstring>
#include <iostream>
using namespace std;

char a[300005];
int head = 100001, tail;
int n;
bool fl = 0;

int main() {
  cin >> (a + 100001) >> n;
  tail = strlen(a + 100001) + 100000;
  while (n--) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      fl = !fl;
    } else {
      char ch;
      int pos;
      cin >> pos >> ch;
      if (pos == 1) {
        if (!fl) {
          a[--head] = ch;
        } else {
          a[++tail] = ch;
        }
      } else {
        if (!fl) {
          a[++tail] = ch;
        } else {
          a[--head] = ch;
        }
      }
    }
  }
  if (!fl) {
    for (int i = head; i <= tail; ++i) {
      putchar(a[i]);
    }
  } else {
    for (int i = tail; i >= head; --i) {
      putchar(a[i]);
    }
  }
  return 0;
}
