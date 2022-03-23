#include<cstdio>
#include<algorithm>


int e[12],n,k;

struct nu {
    int w;
    int num;
} p[20010];

bool cmp(nu a, nu b) {
    if(a.w != b.w)
        return a.w > b.w;
    
    return a.num < b.num;
}

int main() {
    scanf("%d%d", &n, &k);

    for(int i = 0; i < 10; i++)
        scanf("%d", &e[i]);

    for(int i = 0; i < n; i++) {
        scanf("%d", &p[i].w);

        p[i].num = i + 1;
    }

    std::sort(p, p+n, cmp);

    for(int i = 0; i < n; i++)
        p[i].w += e[i % 10];

    std::sort(p, p+n, cmp);

    for(int i = 0; i < k; i++)
        printf("%d ", p[i].num);

    return 0;
}