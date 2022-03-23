#include <cstdio>

int main() {
	int t, s, x;
	scanf("%d%d%d", &t, &s, &x);
	while(1) {
		if(t == x || t + 1 == x) {
			printf("YES");
			return 0;
		}
		t += s;
		if (t > x)
			break;	
	}
	printf ("NO");
	return 0;	
}