#include <iostream>
using namespace std;

int n, a, b, ans = (int)1e9;
int k[210];
bool vis[210];

void dfs(int step, int now) {
    if(step >= ans) {
        return ;
    }
    if(vis[now]) {
        return ;
    }
    if(now < 1 || now > n) {
        return ;
    }
    if(now == b) {
        ans = min(ans, step);
        return ;
    }
    vis[now] = 1;
    dfs(step + 1, now + k[now]);
    dfs(step + 1, now - k[now]);
    vis[now] = 0;
}

int main() {
    cin >> n >> a >> b;
    for(int i = 1; i <= n; ++i) {
        cin >> k[i];
    }
    dfs(0, a);
    if(ans == (int)1e9) {
        cout << "-1";
        return 0;
    }
    cout << ans;
    return 0;
}