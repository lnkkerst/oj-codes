#include <cstdio>
#define MAXN 1000010

int h[MAXN], n;

void swap(int &x, int &y) {
    int t;
    t = x;
    x = y;
    y = t;
}

void siftdown(int i) {
    int t;
    bool flag = 0;

    while(i * 2 <= n && flag == 0) {
        if(h[i] > h[i * 2])
            t = i * 2;
        else
            t = i;

        if(h[t] > h[i * 2 + 1] && i * 2 + 1 <= n)
            t = i * 2 + 1;
        
        if(t != i)
            swap(h[t], h[i]);
        else
            flag = 1;
    }

    return ;
}

void siftup(int i) {
    bool flag = 0;

    if(i == 1)
        return ;

    if(i != 1 && flag ==0) {
        if(h[i] < h[i / 2])
            swap(h[i], h[i / 2]);
        else
            flag = 1;
        
        i /= 2;
    }
}
void add() {
    int x;

    scanf("%d", &x);

    n++;
    h[n] = x;
    siftup(n);

    return ;
}

void del() {
    h[1] = h[n];
    n--;

    siftdown(1);
}

int main() {
    int num;

    scanf("%d", &num);

    for(int i = 1; i <= num; i++) {
        int e;

        scanf("%d", &e);

        if(e == 1)
            add();
        else if(e == 2)
            printf("%d\n", h[1]);
        else if(e == 3)
            del();
    }

    return 0;
}