#include <iostream>
#define int long long
using namespace std;

int f1[100001] = {1, 1}, f2[100001];

int jc(int x) {
    if(f1[x]) return f1[x];
    return f1[x] = jc(x - 1) * x;
}

int C(int m, int n) {
    return jc(n) / (jc(m) * jc(n - m));
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int i, j, k;
        bool fl = 1;
        for(i = 1; i <= 10 && fl; ++i)
            for(j = 2; j <= 100000 && fl; ++j)
                for(k = 1; k <= 10 && fl; ++k)
                    if(i * C(2, j) * k == n) {
                        fl = 0;
                        while(i--) cout << 1;
                        while(j--) cout << 3;
                        while(k--) cout << 7;
                        break;
                    }
        puts("");
    }
    return 0;
}