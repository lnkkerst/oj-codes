#include <stdio.h>

int kmp[2333], n;
char str[2333];

int calc(char s[]) {
    memset(kmp, 0, sizeof(kmp));
    int len = strlen(s + 1), j = 0, ret = 0;
    for(int i = 2; i <= len; ++i) {
        while(j && s[i] != s[j + 1]) j = kmp[j];
        if(s[j + 1] == s[i]) ++j;
        kmp[i] = j;
    }
    for(int i = 1; i <= len; ++i) ret += kmp[i];
    return (len + (len * (len - 1)) / 2) - ret;
}

int main() {
    scanf("%d", &n);
    while(n--) scanf("%s", str + 1), printf("%d\n", calc(str));
    return 0;
}