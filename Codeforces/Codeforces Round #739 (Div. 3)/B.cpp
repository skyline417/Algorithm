#include<bits/stdc++.h>
using namespace std;

int a,b,c;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){

        int ans=0;
        scanf("%d%d%d",&a,&b,&c);
        
        if(a>b) swap(a,b);
//        if(a-1==b-(n/2+1)) 
//        a=b-(n/2)
//        (n-2)=b-a
        int n=(b-a)*2;
		
		
        if(b<(n/2+1) || c>n || a>n || b>n ) puts("-1");
        else {
        	if(c>=(n/2+1)){
        		cout<<c-(n/2);
			}else{
				cout<<c+(n/2);
			}
			puts("");
        }
        

    }
    return 0;
}
