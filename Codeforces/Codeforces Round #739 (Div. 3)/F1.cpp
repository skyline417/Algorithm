#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k;
set<ll>s1,s2;
int main(){
	int cnt=0;
	for(int i=0;i<10;++i){
		for(int j=i+1;j<10;++j){
			for(int k=0;k<(1<<10);++k){ //9位二进制枚举 1000000000
				ll s=0;
				
				for(int o=0;o<10;++o){
					if( (k>>o)&1 ){
						s=s*10+i;
					}else{
						s=s*10+j;
					}
					s2.insert(s);
					++cnt;
				}

			}
		}
	}
	cout<<cnt<<endl;
	cout<<s2.size()<<endl;
	for(int i=1;i<10;++i){
		ll s=0;
		for(int k=1;k<=10;++k){
			s=s*10+i;
			s1.insert(s);
			//s2.insert(s);
		}
	}
	
	
    int T;
    cin>>T;
    while(T--){
    	scanf("%lld%lld",&n,&k);
    	if(k==1){
    		cout<<*s1.lower_bound(n);
		}else{
			cout<<*s2.lower_bound(n);
		}
		puts("");
	}
    return 0;
    
}
