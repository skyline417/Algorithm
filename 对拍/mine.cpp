#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	freopen("mine.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
    	
		int a,b;
    	scanf("%d%d",&a,&b);
    	int n=a+b;
		cout<<"input: "<<a<<" "<<b<<endl;
    	set<int>ss;
	/* 
		该方break数 
				至少是该方赢数-该方轮数（在该方的轮次赢满） 
				不超过该方赢数
				不超过对方赢数
	 	总break数
		 		=该方break+对方break
		若该方break为i，则此时对方break为
	
		对方在该方的轮次的赢数
		=对方的赢数-对方在对方轮次的赢数
		=对方的赢数-(对方轮次-该方break) 
	*/
		if(n&1){
			//a:n/2 b:n/2+1 
			for(int i=max(a-n/2,0);i<=min(a,b);++i){
				ss.insert(i+b-(n/2+1-i));
			}
			
			for(int i=max(b-(n/2-1),0);i<=min(a,b);++i){
				ss.insert(i+a-(n/2-i));
			}
				 
		}else{
			//a:n/2 b:n/2
			for(int i=max(a-n/2,0);i<=min(a,b);++i){
				ss.insert(i+b-(n/2-i));
			}
			
			for(int i=max(b-n/2,0);i<=min(a,b);++i){
				ss.insert(i+a-(n/2-i));
			}
		}
		for(auto e:ss){
			ss.insert(n-e);
		}
		cout<<ss.size()<<endl;
		for(auto e:ss){
			cout<<e<<" ";
		}
		puts("");
        
    }
    return 0;
}
