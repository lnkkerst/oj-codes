#include <bits/stdc++.h>
using namespace std;

struct Node {
    int l, r;
} a[1000010];

bool cmp(Node a, Node b) {
    if(a.r == b.r) return a.l < b.l;
    return a.r < b.r;
}

bool vis[1000010];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i].l >> a[i].r;
    sort(a + 1, a + n + 1, cmp);
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        if(!vis[i]) {
            vis[i] = 1;
            ++ans;
            for(int j = i + 1; j <= n; ++j)
                if(a[j].l < a[i].r)
                    vis[j] = 1;
        }
    cout << ans;
    return 0;
}