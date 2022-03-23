#include <stdio.h>
#include <malloc.h>

struct Node {
    int dat;
    struct Node *nex;
} ;

int i, j, k;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    struct Node *head, *tmp, *pre;
    head = (struct Node *)malloc(sizeof(struct Node));
    pre = head;
    for(i = 1; i <= n; ++i) {
        tmp = (struct Node *)malloc(sizeof(struct Node));
        tmp->dat = i;
        tmp->nex = NULL;
        pre->nex = tmp;
        pre = tmp;
    }
    tmp->nex = head->nex;
    tmp = head->nex;
    for(i = 1; i <= n; ++i) {
        for(j = 1; j <= m - 2; ++j) {
            tmp = tmp->nex;
        }
        pre = tmp->nex;
        printf("%d ", pre->dat);
        tmp->nex = tmp->nex->nex;
        free(pre);
    }
    free(head);
    return 0;
}