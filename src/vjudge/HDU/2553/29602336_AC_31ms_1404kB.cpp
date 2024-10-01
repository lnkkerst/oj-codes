#include <iostream>
using namespace std;

int main() {
  int ans[] = {0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724};
  int n;
  while (true) {
    cin >> n;
    if (!n) {
      return 0;
    }
    cout << ans[n] << endl;
  }
}
