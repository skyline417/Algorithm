#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int n,k;
 
int main(){
	
	
	set<ll> ss[2];
	//int num=0;
	for(int i=0;i<10;++i){
		for(int j=i+1;j<10;++j){
			for(int k=2;k<=9;++k){
				for(int o=1;o<k;++o){ //o ºÍ k-o 
					string s;
					for(int p=1;p<=o;++p){
						s+=(i+'0');
					}
					for(int p=1;p<=k-o;++p){
						s+=(j+'0');
					}
					
					//if(s2.count(s)) cout<<"debug1: "<<s<<endl;
					if(s[0]!='0') ss[0].insert(atoi(s.c_str()));//, ++num;
					while(next_permutation(s.begin(),s.end())){
						//if(s2.count(s)) cout<<"debug2: "<<s<<endl;
						if(s[0]!='0') ss[0].insert(atoi(s.c_str()));//, ++num;
					} 
				}
				
			}
		}
	}
 
	ss[0].insert(1000000000);
	
 
	//cout<<"cnt: "<<cnt<<"  size:"<<ss[0].size()<<endl ;
	for(int i=1;i<10;++i){
		//string s;
		ll s=0;
		for(int k=1;k<=10;++k){
			//s+=(i+'0');
			s=s*10+i;
			ss[1].insert(s);
			ss[0].insert(s);
			//++num;
		}
	}
 	//cout<<num+1<<endl;
 	
 	
    int T;
    scanf("%d",&T);
    while(T--){
    	
        scanf("%d%d",&n,&k);
        
        
        
//        auto l=ss[k&1].begin(), r=ss[k&1].end();
//        --r;
//        while(*l<=*r){
//        	auto mid=(l+r)/2;
//        	if(*mid>=n){
//        		ans=*mid;
//        		r=mid-1;
//			}else{
//				l=mid+1;
//			}
//		}
		cout<<*ss[k&1].lower_bound(n)<<endl;     
        
 
        
    }
    
    return 0;
    
}
