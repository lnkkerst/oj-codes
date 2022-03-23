#include <cstdio>
#include <algorithm>
#define MAXN 5001

struct mem{
	int num;
	int score;
}a[MAXN];

int n,m;

bool cmp(mem a, mem b) {
	if (a.score < b.score)
		return 0;
	return 1;
}

int main() {
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].num, &a[i].score);
	
	std::sort(a + 1, a + n + 1, cmp);
	
	int tmp = a[int (m * 1.5)].score;
	
	printf("%d ", tmp);
	
	int i = 1;
	
	while(i <= n) {
		if (a[i].score < tmp) {
			i--;
			break;
		}
		i++;
	}
	
	printf("%d\n", i);
	
	for (int j = 1; j <= i; j++)
		printf("%d %d\n", a[j].num, a[j].score);
	return 0;
}