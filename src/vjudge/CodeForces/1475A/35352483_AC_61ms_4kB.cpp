#include <iostream>
using namespace std;

#define int long long
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        while(!(x % 2)) {
            x >>= 1;
        }
        cout << (x == 1 ? "NO" : "YES") << endl;
    }
    return 0;
}