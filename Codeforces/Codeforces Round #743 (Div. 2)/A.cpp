#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        int ans=0;
        scanf("%d",&n);
        string s;
        cin>>s;
        int cnt=0;
        for(int i=0;s[i];++i){
        	if(s[i]!='0') ++cnt;
        	ans+=s[i]-'0';
        }
        if(s[n-1]=='0') ans+=cnt;
        else ans+=cnt-1;
		//cout<<"ans-------------";
	
        printf("%d\n",ans);
    }
    return 0;
}
