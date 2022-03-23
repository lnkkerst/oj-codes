#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    const auto &gcd = [](const int a, const int b) -> int {
        const auto &f = [&](auto &&self, const int a, const int b) -> int {
            return b > 0 ? self(self, b, a % b) : a;
        };
        return f(f, a, b);
    };
    while (t--) {
        string a, b;
        cin >> a >> b;
        string sa, sb;
        int l = a.length() * b.length() / gcd(a.length(), b.length());
        for(int i = 1; i <= l / a.length(); ++i) {
            sa.append(a);
        }
        for(int i = 1; i <= l / b.length(); ++i) {
            sb.append(b);
        }
        cout << (sa == sb ? sa : "-1") << endl;
    }
    return 0;
}