#include <cstring>
#include <iostream>
using namespace std;

char a[3000000];
int head = 1000001, tail;
int n;
bool fl = 0;

int main() {
  cin >> (a + 1000001) >> n;
  tail = strlen(a + 1000001) + 1000000;
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
