#include <iostream>
#include <cmath>

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::string s;
    s += std::string(a + (bool)b, '0');
    s += std::string(c + (bool)b, '1');
    if(s.empty()) s += '1';
    for(int i = 1; i < b; ++i) {
        if(s.back() == '1') s += '0';
        else s += '1';
    }
    if(s.length() != a + b + c + 1) s += s.back();
    std::cout << s << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    for(int i = 1; i <= t; ++i) {
        solve();
    }
    return 0;
}