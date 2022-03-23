#include<cstdio>
const int MAXN=100001;
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
    int n,m,a[MAXN]={0},i,j,x,y;
    long long ans;
    char event;
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++) scanf("%d",&a[i]);
    for (i=1;i<=2*m;i++){
        scanf("%c",&event);
        if (event=='Q'){
            ans=0;
            for (j=1;j<=n;j++) ans+=a[j];
            printf("%lld\n",ans);
            continue;
        }
        if (event=='D'){
            scanf("%d",&x);
            a[x]=0;
            continue;
        }
        if (event=='C'){
            scanf("%d%d",&x,&y);
            a[x]-=y;
            continue;
        }
        if (event=='I'){
            scanf("%d%d",&x,&y);
            a[x]=y;
            if (x>n)
            n=x;
            continue;
        }
    }
    return 0;
}