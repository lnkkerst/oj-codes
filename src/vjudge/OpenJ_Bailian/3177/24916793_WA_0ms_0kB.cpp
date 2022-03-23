#include <iostream>
using namespace std;

bool pd(int x) {
    if(x == 1) return 0;
    if(x == 2 || x == 3) return 1;
    if(x % 6 != 1 && x % 6 != 5) return 0;
    for(int i = 5; i * i <= x; i += 6)
        if(!(x % i) || !(x % (i + 2)))
            return 0;
    return 1;
}

int main() {
    int l, r, ans = 0;
    cin >> l >> r;
    for(int i = l; i <= r; ++i)
        if(pd(i)) ++ans;
    cout << ans;
    return 0;
}