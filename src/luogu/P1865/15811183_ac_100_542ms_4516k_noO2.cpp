#include <cstdio>
#include <cmath>

int m, n, sum = 0, a[1000010];

bool pd(int a){
    if(a == 1)
        return 0;

    if(a == 2 || a == 3)
        return 1;

    if(a % 6 != 1 && a % 6 != 5)
        return 0;

    for(int i = 5; i <= sqrt(a); i += 6)
        if(a % i == 0 || a % (i + 2) == 0)
            return 0;

    return 1;
}

int main() {
    scanf("%d%d", &n, &m);
    
    for(int i = 1; i <= m; i++) {
    	sum += pd(i);
    	a[i] = sum;
	}
	
	for(int i = 1; i <= n; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		if(l < 1 || r > m)
			printf("Crossing the line\n");
		else
			printf("%d\n", a[r] - a[l - 1]);
	}
	
	return 0;
}