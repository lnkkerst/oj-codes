//
// Created by lnkkerst on 2020/4/27/027.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int base = 1, ans = 0;
    for(auto i : s) {
        ans += (i - '0') * base;
        base *= 8;
    }
    cout << ans;
    return 0;
}