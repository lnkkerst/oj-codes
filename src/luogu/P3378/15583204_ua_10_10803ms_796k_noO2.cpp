#include <cstdio>
#define MAXN 1000010

int h[MAXN], n, num;

int max(int x, int y) {
    return x > y ? x : y;
}

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
        
        if(h[t] > h[i * 2 + 1])
            t = i * 2 + 1;
        
        swap(h[i], h[t]);
    }
}

void siftup(int position)
{
    int child=position;
    int father=(child-1)/2;
 
    int temp=h[position];
 
    while(father>=0 && child>=1)
    {
        if(h[father]>temp)
        {
            h[child]=h[father];
 
            child=father;
            father=(child-1)/2;
        }
        else
            break;
    }
 
    h[child]=temp;
}

void del() {
    int t = h[1];

    h[1] = h[n];
    n--;
    siftdown(1);
}

void add() {
    int x;

    scanf("%d", &x);

    h[++n] = x;

    siftup(n);
}

int main() {
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