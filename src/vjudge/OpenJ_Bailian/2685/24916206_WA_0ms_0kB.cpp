#include <iostream>
using namespace std;

int main() {
  for (int i = 0; i <= 9; ++i)
    for (int j = 0; j <= 9; ++j)
      for (int k = 0; k <= 9; ++k)
        if (i * i * i + j * j * j + k * k * k == i * 100 + j * 10 + k)
          cout << i * 100 + j * 10 + k << ' ';
  return 0;
}