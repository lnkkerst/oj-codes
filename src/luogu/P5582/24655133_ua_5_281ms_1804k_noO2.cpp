#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    bool a[1000010];
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i) {
        int n, k;
        if(n == 1) {
            printf("-1\n");
            continue;
        }
        memset(a, 0, sizeof(a));
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= k; ++i) {
            int tmp;
            scanf("%d", &tmp);
            a[tmp] = 1;
        }
        bool f = 0;
        for(int i = 1; i <= n; ++i) {
            if(!a[i]) {
                int x = i;
                if((x != 0) && (x != 1)) {
                    x = n % x;
                }
                if(x) {
                    f = 1;
                    break;
                }
            }
        }
        printf("%d\n", f ? n : -1);
    }
    return 0;
}