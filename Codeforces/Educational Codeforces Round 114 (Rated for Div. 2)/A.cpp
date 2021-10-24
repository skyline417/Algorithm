#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        int ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
        	string s;
        	for(int j=1;j<=i;++j){
        		s+='(';
			}
			for(int j=1;j<=i;++j){
				s+=')';
			}
			for(int j=1;j<=n-i;++j){
				s+='(';
			}
			for(int j=1;j<=n-i;++j){
				s+=')';
			}
			cout<<s<<endl;
		}
    }
    return 0;
}
