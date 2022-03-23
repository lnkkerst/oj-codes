#include <iostream>
using namespace std;

char s[55];
int dep[55];
int len;

int dfs(int l, int r, int depth) {
    // cout << endl << l << ' ' << r << endl;
    if(l == r - 1) return 1;
    int ret = 0;
    for(int i = l + 1; i <= r - 1; ++i) {
        if(dep[i] == depth) {
            for(int j = i + 1; j <= r - 1; ++j) {
                if(dep[j] == depth) {
                    ret += dfs(i, j, depth + 1);
                    i = j;
                    break;
                }
            }
        }
    }
    return ret * 2;
}

int main() {
    cin >> (s + 1);
    while(s[++len]);
    --len;
    int cnt = 1;
    for(int i = 1; i <= len; ++i) {
        if(s[i] == '(')
            dep[i] = ++cnt;
        else dep[i] = cnt--;
    }
    dep[0] = dep[len + 1] = 1;
    cout << (dfs(0, len + 1, 2) / 2);
    return 0;
}