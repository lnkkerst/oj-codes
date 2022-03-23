#include <cstdio>
char a[10001][100001], b[10001][100001];
int cnta[10001], cntb[10001];
int la, lb, t, ans;
int main() {
	while(1) {
		++la;
        char c;
		while(c = getchar(), c != '\n')
			if(c == '<')
                if(cnta[la]) --cnta[la];
            else a[la][++cnta[la]] = c;
		if(a[la][1] == 'E' && a[la][2] == 'O' && a[la][3] == 'F') break;
	} --la;
	while(1) {
		++lb;
        char c;
		while(c = getchar(), c != '\n')
			if(c == '<' && cntb[lb]) --cntb[lb];
            else b[lb][++cntb[lb]] = c;
		if(b[lb][1] == 'E' && b[lb][2] == 'O' && b[lb][3] == 'F') break;
	} --lb;
	scanf("%d", &t);
	int minl = la > lb ? lb : la;
	for(int i = 1; i <= minl; ++i) {
		int mins = cnta[i] > cntb[i] ? cntb[i] : cnta[i];
		for(int j = 1; j <= mins; ++j)
			ans += a[i][j] == b[i][j];
	}
    printf("%d\n", (int)(ans * 60 / (double)t));
	return 0;
}