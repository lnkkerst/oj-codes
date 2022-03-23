#include <iostream>
using namespace std;

int solve(int x) {
    int fl = 1;
    if(x < 0) x = -x, fl = -1;
    int ret = 0;
    while(x) {
        ret *= 10, ret += x % 10;
        x /= 10;
    }
    return ret * fl;
}

int main() {
    int x;
    while(cin >> x) cout << solve(x) << endl;
    return 0;
}