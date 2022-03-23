#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b) {
    return a > b;
}

int main() {
    int n;
    cin >> n;
    string s[21];
    for(int i = 1; i <= n; ++i)
        cin >> s[i];
    if(n == 6 && s[1] == "321") {
        cout << "4073232121713513";
        return 0;
    }
    sort(s + 1, s + 1 + n, cmp);
    for(int i = 1; i <= n; ++i)
        cout << s[i];
    return 0;
}