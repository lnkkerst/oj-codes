
#include <cstdio>

int n, a[30];
char s1[30], s2[30], s3[30];
bool b[30], o;

int mod(int x) {
	return x >= n ? x - n : x;
}
int div(int x) {
	return x >= n ? 1 : 0;
}

bool pan(int t) {
    for (int i = t;i >= 1;i--) {
        int id1 = s1[i] - 'A',id2 = s2[i] - 'A',id3 = s3[i] - 'A';
		if (a[id1] != -1 && a[id2] != -1 && a[id3] != -1)
        	if (mod(a[id1] + a[id2]) != a[id3] && mod(a[id1] + a[id2] + 1) != a[id3])
				return 0;
        if (i == 1) 
        	if (a[id1] != -1 && a[id2] != -1) 
        		if (a[id1]+a[id2]>=n)
					return 0;
    }
    return 1;
}

void dfs(int t, int tmp) {
    if (t == 0) {
        if (tmp)
			return ;
        for (int i = 0; i < n; i++)
        	printf ("%d ", a[i]);
        o = true;
        return ;
    }
    if (! pan(t))
		return ;
    int id1 = s1[t] - 'A', id2 = s2[t] - 'A', id3 = s3[t] - 'A';
    if (a[id1] != -1 && a[id2] != -1 && a[id3] != -1) {
        if (a[id3] != mod(a[id1] + a[id2] + tmp))
			return ;
        dfs(t - 1, div(a[id1] + a[id2] + tmp));
        return ;
    }
    if (a[id1] != -1 && a[id2] != -1 && a[id3] == -1) {
        if (b[mod(a[id1] + a[id2] + tmp)])
			return ;
        a[id3] = mod(a[id1] + a[id2] + tmp);
        b[a[id3]] = 1;
        dfs(t - 1, div(a[id1] + a[id2] + tmp));
        b[a[id3]] = 0;
        a[id3] = -1;
        return ;
    }
    if (a[id1] != -1 && a[id2] == -1 && a[id3] != -1) {
        if (b[mod(a[id3] - a[id1] - tmp + n)])
			return ;
        a[id2] = mod(a[id3] - a[id1] - tmp + n);
        b[a[id2]] = 1;
        dfs(t - 1, div(a[id1] + a[id2] + tmp));
        b[a[id2]] = 0;
        a[id2] = -1;
        return ;
    }
    if (a[id1] == -1 && a[id2] != -1 && a[id3] != -1) {
        if (b[mod(a[id3] - a[id2] - tmp + n)])
			return ;
        a[id1] = mod(a[id3] - a[id2] - tmp + n);
        b[a[id1]] = 1;
        dfs(t - 1, div(a[id1] + a[id2] + tmp));
        b[a[id1]] = 0;
        a[id1] = -1;
        return ;
    }
    bool p1, p2, p3;
    for (int i = (a[id1] == -1 ? 0 : a[id1]); i < (a[id1] == -1 ? n : a[id1]+1); i++)
    	if ((a[id1] == -1 && ! b[i]) || a[id1] == i) {
        	if ( ! b[i])
				p1 = 1;
			else
				p1 = 0;
        	a[id1] = i;
			b[i] = 1;
        	for (int j = (a[id2] == -1 ? 0 : a[id2]); j < (a[id2] == -1 ? n : a[id2] + 1); j++)
        	if ((a[id2]==-1&&!b[j])||a[id2]==j) {
        	    if ( ! b[j])
					p2 = 1;
				else
					p2 = 0;
        	    a[id2] = j; b[j] = 1;
        	    if ((a[id3] == -1 && ! b[mod(a[id1] + a[id2] + tmp)]) || a[id3] == mod(a[id1] + a[id2] + tmp)) {
        	        if (! b[mod(a[id1] + a[id2] + tmp)])
						p3 = 1;
					else
						p3 = 0;
        	        a[id3] = mod(a[id1] + a[id2] + tmp);
            	    b[a[id3]] = 1;
            	    dfs(t - 1, div(a[id1] + a[id2] + tmp));
					if (o)
						return ;
                	if (p3) {
						b[a[id3]] = 0;
						a[id3] = -1;
					}
            	}
            	if (p2) {
            		a[id2] = -1;
					b[j] = 0;
				}
        	}
        	if (p1){
				a[id1] = -1;
				b[i] = 0;
			}
    	}
}

int main() {
    scanf("%d", &n);
    scanf("%s%s%s", s1 + 1, s2 + 1, s3 + 1);
    for (int i = 0; i < n; i++)
		a[i] = -1;
    dfs(n, 0);
    return 0;
}