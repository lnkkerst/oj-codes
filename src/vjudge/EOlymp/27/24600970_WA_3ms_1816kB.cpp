#include <iostream>
using namespace std;

int x, c1, c2;

int main() {
    cin >> x;
    int t = x;
    while(t) {
        c1 += t % 2;
        t >>= 1;
        ++c2;
    }
    int ans = 0;
    for(int i = c2; c1; --c1, --i) 
        ans += 1 << (i - 1);
    cout << ans;
    return 0;
}