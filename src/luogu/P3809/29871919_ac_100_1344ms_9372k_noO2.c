#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[1000010];
int sa[1000010];

int cmp(const void *a, const void *b) {
    return strcmp(&str[*(int*)a], &str[*(int*)b]);
}

int main() {
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0; i < len; ++i) sa[i] = i;
    qsort(sa, len, sizeof(int), cmp);
    for(int i = 0; i < len; ++i) printf("%d ", sa[i] + 1);
    return 0;
}