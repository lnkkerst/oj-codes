#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

int a[20], f[10] = {0, 1};
int n, ans;

void dfs(int pos) {
    if(pos == n + 1) {
        int num = 0, tot = 0;
        for(int i = 1; i <= n; ++i)
            num *= 10, num += a[i], tot += f[a[i]];
        if(num == tot) ++ans;
        return ;
    }
    for(int i = 1; i <= 9; ++i) {
        a[pos] = i;
        dfs(pos + 1);
    }
}

signed main() {
    for(int i = 2; i <= 9; ++i) f[i] = f[i - 1] * i;
    while(cin >> n) {
        dfs(1);
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}