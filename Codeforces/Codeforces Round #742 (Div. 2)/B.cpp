#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;

int S[N];
int main(){
    int T;
    scanf("%d",&T);
    for(int i=1;i<=N;++i){
    	S[i]=S[i-1]^i;
	}
    while(T--){
        int a,b;
        int ans=0;
        scanf("%d%d",&a,&b);
        ans=0;
        if(S[a-1]!=b){
        	if((S[a-1]^b)==a){
        		a+=2;
			}else{
				a+=1;
			}
		}
        printf("%d\n",a);
    }
    return 0;
}

