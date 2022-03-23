// luogu-judger-enable-o2
#include<cstdio>
using namespace std;
int main(){
	int ans[10]={0},m,n,s;
	scanf("%ld%ld",&m,&n);
	for (int i=m;i<=n;i++){
		s=i;
		while (s>0){
			ans[s%10]++;
			s=s/10;
		}
	}
	for (int i=0;i<10;i++) printf("%ld ",ans[i]);
	return 0;
}