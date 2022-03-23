#include <bits/stdc++.h>
using namespace std;
 
char s[1000010];
int n, fa[1000010];
 
string getstr(int x) {
    string ret;
    int now = x;
    while(now) {
        ret.push_back(s[now]);
        now = fa[now];
    }
    int len = (int)ret.length();
    for(int i = 0; i < len / 2; ++i)
        swap(ret[i], ret[len - i - 1]);
    return ret;
}
 
int work(int x) {
    int ret = 0;
    string str = getstr(x);
    int len = (int)str.length();
    for(int i = 0; i < len; ++i) {
        int count = 0;
        bool f = 1;
        for(int j = i; j < len; ++j) {
            if(str[j] == '(') ++count;
            else {
                if(count == 0) f = 0;
                --count;
            }
            if(!count && f) ++ret;
        }
    }
    // cout << str << endl;
    return ret;
}
 
int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> s[i];
    for(int i = 2; i <= n; ++i) cin >> fa[i];
    int ans = 0;
    for(int i = 2; i <= n; ++i)
        ans ^= i * work(i);
    cout << ans;
    return 0;
}