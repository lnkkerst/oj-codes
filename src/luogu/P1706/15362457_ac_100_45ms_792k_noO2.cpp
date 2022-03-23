#include <cstdio>
#define MAXN 15

int a[MAXN], n;
bool b[MAXN] ={false};

void dfs(int i) {
    if(i == n + 1) {
        for(int j = 1; j <= n; j++)
            printf("%5d", a[j]);
            
        putchar('\n');
        
        return ;
    }
    
    for(int j = 1; j <= n; j++) {
        if(! b[j]) {
            b[j] = true;
            a[i] = j;
            
            dfs(i + 1);
            
            b[j] = false;
        }
    }
}

int main() {
    scanf("%d", &n);
    
    dfs(1);
    
    return 0;
}