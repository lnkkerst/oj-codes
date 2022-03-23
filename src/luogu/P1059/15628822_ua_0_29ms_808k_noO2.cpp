#include <cstdio>
#include <algorithm>
int main() {
    // int a[] = {1, 2, 2, 2, 2, 6, 7, 8 ,9};

    // std::fill(a, a + 4, 10);

    // std::random_shuffle(a, a + 9);
    // for(int i = 0; i < 9; i++)
    //     printf("%d ", a[i]);

    //     putchar('\n');

    // std::stable_sort(a, a + 9);

    // for(int i = 0; i < 9; i++)
    //     printf("%d ", a[i]);

    // printf("%d ", *std::max_element(a, a + 9));

    // printf("%d", *std::upper_bound(a, a + 9, 8));

    // std::unique(a, a + 9);

    // for(int i = 0; i <= 8; i++)
    //     printf("%d ", a[i]);

    int n, a[2000];
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    std::sort(a + 1, a + n + 1);

    for(int i = 1; i <= *(std::unique(a, a + n + 1) - (a[1])); i++)
        printf("%d ", a[i]);

    return 0;
}