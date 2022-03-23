#include <stdio.h>

struct Trie {
    int go[128], end;
} t[233333];

int cnt, n, ans;
char str[2333];

void insert(char s[]) {
    int len = strlen(s);
    int l = 0, size = 1;
    while(size <= len) {
        if(size + l > len) {
            ++size;
            l = 0;
            continue;
        }
        int now = 0;
        for(int i = l; i < l + size; ++i) {
            int v = s[i];
            if(!t[now].go[v]) t[now].go[v] = ++cnt;
            now = t[now].go[v];
        }
        if(t[now].end != 1) ++ans;
        t[now].end = 1;
        ++l;
    }
}

int query(char s[]) {
    memset(t, 0, sizeof(t));
    cnt = ans = 0;
    insert(s);
    // dfs(0);
    return ans;
}

int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%s", str);
        printf("%d\n", query(str));
    }
}