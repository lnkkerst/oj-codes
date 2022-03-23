#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, ans = 0;
    cin >> n;
    unordered_map<string, int> b;
    for(int i = 1; i <= n; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        s1 = s1.substr(0, 2);
        if(s1 != s2) {
            ans += b[s1 + s2];
        }
        ++b[s2 + s1];
    }
    cout << ans;
    return 0;
}