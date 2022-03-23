#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 2333333333333;

unordered_map<int , bool > b;
int n;
char str[23333];
signed main() {
    scanf("%d", &n);
    while(n--) {
        b.clear();
        scanf("%s", str + 1);
        int len = strlen(str + 1), ans = 0;
        for(int i = 1; i <= len; ++i) {
            int hash = 0;
            for(int j = i; j <= len; ++j) {
                hash = (hash * 26 + str[j] - 'a') % MOD;
                if(!b[hash]) ++ans, b[hash] = 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}