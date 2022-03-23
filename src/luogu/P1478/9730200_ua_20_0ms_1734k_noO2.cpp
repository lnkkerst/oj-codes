#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int n,s,a,b,c,i,j=0,ans=0;
	scanf("%ld%ld%ld%ld",&n,&s,&a,&b);
	c=a+b;
	const int N=n;
	int y[N];
	for (i=0;i<n;i++) {
		scanf("%ld%ld",&a,&b);
		if (a<=c){
			y[j]=b;
			j++;
		}
	}
	sort (y,y+j);
	for (i=0;i<j;i++){
		if (s-y[i]<0) break;
		s=s-y[i];
		ans++;
	}
	printf("%ld",ans);
	return 0;
}