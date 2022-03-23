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
    sort(s + 1, s + 1 + n, cmp);
    for(int i = 1; i <= n; ++i)
        cout << s[i];
    return 0;
}