#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int T;
	cin>>T;
	for(int Case=1;Case<=T;++Case){
		ll c,d,n,m;
		cin>>n>>d>>c>>m;
		string s;
		cin>>s;
		int i=0;
		for(i;s[i];++i){
			if(s[i]=='D'){
				if(d==0) break;
				--d;
				c+=m;
			}else{
				if(c==0) break;
				--c;
			}
		}
		string ans="YES";
		for(;s[i];++i){
			if(s[i]=='D') ans="NO";
		}
		printf("Case #%d: ",Case);
		cout<<ans<<endl;
	}
}
