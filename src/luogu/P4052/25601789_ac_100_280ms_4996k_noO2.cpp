#include <bits/stdc++.h>
using namespace std;
const int MOD = 10007;
 
int read() {
    int ret;
    bool flag = 0;
    char ch;
    while(!isdigit(ch = getchar())) (ch == '-') && (flag = 1);
    for(ret = ch - '0'; isdigit(ch = getchar()); ret *= 10, ret += ch - '0');
    return flag ? -ret : ret;
}

void print(int x) {
    if(x < 0) { putchar('-'); x *= -1; }
    if(x > 9) { print(x / 10); }
    putchar(x % 10 + '0');
}

struct Trie {
    int go[26], end, fail;
} trie[10010];

char s[10010];
int cnt = 0;
int f[110][10010];
int ans = 0;

void insert(char *str) {
    int l = strlen(s);
    int x = 0;
    for(int i = 0; i < l; i++) {
        int k = str[i] - 'A';
        if(!trie[x].go[k])
            trie[x].go[k] = ++cnt;
        x = trie[x].go[k];
    }
    trie[x].end |= 1;
}

void init_fail() {
    queue<int > q;
    for(int i = 0; i < 26; ++i)
        if(trie[0].go[i])
            q.push(trie[0].go[i]);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < 26; ++i) {
            if(trie[u].go[i]) {
                trie[trie[u].go[i]].end |= trie[trie[trie[u].fail].go[i]].end;
                trie[trie[u].go[i]].fail = trie[trie[u].fail].go[i];
                q.push(trie[u].go[i]);
            }
            else trie[u].go[i] = trie[trie[u].fail].go[i];
        }
    }
}

int main() {
    int n = read(), m = read();
    for(int i = 1; i <= n; ++i)
        scanf("%s", s), insert(s);
    init_fail();
    f[0][0] = 1;
    for(int i = 1; i <= m; ++i)
        for(int j = 0; j <= cnt; ++j)
            for(int k = 0; k < 26; ++k)
                if(!trie[trie[j].go[k]].end)
                    (f[i][trie[j].go[k]] += f[i - 1][j]) %= MOD; 
    for(int i = 0; i <= cnt; ++i)
        (ans += f[m][i]) %= MOD;
    int sum = 1;
    for(int i = 1; i <= m; ++i)
        sum = sum * 26 % MOD;
    printf("%d\n", (sum - ans + MOD) % MOD);
    return 0;
}