#include <bits/stdc++.h>
const int MAXN = 11000010;
using namespace std;

int main() {
    char ch, s[MAXN<<1];
    int p[MAXN<<1], cnt = 1;
    s[0] = '~', s[1] = '#';
    while(!isalpha(ch = getchar()));
    for(s[++cnt] = ch, s[++cnt] = '#'; isalpha(ch = getchar()); s[++cnt] = ch, s[++cnt] = '#');
    int id, mx = 0;
    for(int i = 1; i < cnt; ++i) {
        if(mx > 1) p[i] = min(p[2 * id - i], mx - i);
        else p[i] = 1;
        while(s[i + p[i]] == s[i - p[i]]) ++p[i];
        if(i + p[i] > mx) mx = i + p[i], id = i;
    }
    printf("%d\n", *max_element(p + 1, p + cnt + 1) - 1);
    return 0;
}
