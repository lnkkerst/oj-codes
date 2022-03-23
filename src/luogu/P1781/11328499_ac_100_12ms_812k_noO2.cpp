#include <cstdio>
#include <cstring>
#define MAXN 200

bool Strcmp(char *a, char *b) {
	for (int i = 0; i < strlen(a); i ++) {
		if (a[i] == b[i]) continue;
		else {
			if (a[i] > b[i])
				return true;
			else return false;
		}
	}
}

int main() {
	int n, ansm, lt, la;
	char ans[MAXN], tmp[MAXN];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &tmp);
		la = strlen(ans);
		lt = strlen(tmp);
		if(lt > la) strcpy(ans, tmp),ansm = i + 1;
		else if (la == lt && Strcmp(tmp, ans)==true) strcpy(ans, tmp),ansm = i + 1;
	}
	printf("%d\n%s", ansm ,ans);
	return 0;
}