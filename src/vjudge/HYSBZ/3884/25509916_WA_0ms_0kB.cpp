#include <iostream>
#define int long long
using namespace std;

int calc(int x) {
    int ans = x;
    for(int i = 2; i * i <= x; ++i) {
        if(!(x % i)) {
            ans = ans / i * (i - 1);
            while(!(x % i)) x /= i;
        }
    }
    if(x > 1) ans = ans / x * (x - 1);
    return ans;
}

int solve(int x) {
    if(x == 2) return 0;
    if(x == 3) return 1;
    if(x == 6) return 4;
    return ((1 << (solve(calc(x)))) % x);
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        cout << solve(x) << endl;
    }
}