#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
char s[N];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d%s",&n,s+1);
        int l1=-1,r1,l2,r2;
		for(int i=1;s[i];++i){
			if(s[i]=='0'){
				l1=i;
				break;
			}
		}
		if(l1==-1){
			l1=1,r1=n/2,l2=n-n/2+1,r2=n;
		}else if(n-l1+1<=n/2){
			r1=l1-1,r2=l1,l1=1,l2=1;
		}else{
			r1=n,l2=l1+1,r2=n;
		}
		
		printf("%d %d %d %d\n",l2,r2,l1,r1);

    }
    return 0;
}
