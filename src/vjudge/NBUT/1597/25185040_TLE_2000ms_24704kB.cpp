#include <iostream>
#include <cstring>
#define int long long
using namespace std;

struct Trie {
    int cnt, root, go[1500000][2];
    Trie() {clear();}
    void clear() {
        memset(go, 0, sizeof(go));
        root = cnt = 0;
    }
    void add(int num) {
        int now = root;
        for(int i = 31; i >= 0; --i) {
            int k = (num >> i) & 1;
            if(!go[now][k]) go[now][k] = ++cnt;
            now = go[now][k];
        }
    }
    int query(int num) {
        int now = root, ret = 0;
        for(int i = 31; i >= 0; --i) {
            int k = !((num >> i ) & 1);
            if(go[now][k]) {
                ret |= (1 << i);
                now = go[now][k];
            }
            else now = go[now][!k];
        }
        return ret;
    }
} b;

int a[100010];

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; ++i)
            cin >> a[i], b.add(a[i]);
        int ans = 0;
        for(int i =1 ; i <= n; ++i)
            ans = max(ans, b.query(a[i]));
        cout << ans << endl;
        b.clear();
    }
    return 0;
}