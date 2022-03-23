#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int last;
    cin >> last;
    int ans = 1000000000;
    for(int i = 1; i <= n - 1; ++i) {
        int x;
        cin >> x;
        ans = min(ans, x - last);
        last = x;
    }
    cout << ans;
    return 0;
}