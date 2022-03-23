#include <bits/stdc++.h>
using namespace std;
int kmp[233], ans;
char a[233], b[233] = " 1";

int main() {
    scanf("%s", a + 1);
    int la = strlen(a + 1), lb = strlen(b + 1), j = 0;
    for(int i = 2; i <= lb; ++i) {
        while(j && b[i] != b[j + 1]) j = kmp[j];
        if(b[j + 1] == b[i]) ++j;
        kmp[i] = j;
    } j = 0;
    for(int i = 1; i <= la; ++i) {
        while(j > 0 && b[j + 1] != a[i]) j = kmp[j];
        if(b[j + 1] == a[i]) ++j;
        if(j == lb) ++ans,  j = kmp[j];
    }
    printf("%d", ans);
    return 0;
}