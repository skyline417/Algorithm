#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
struct node{
    int x,y,id;
    bool operator < (const node& t) const {
        return x<t.x;
    }
}c[N];
bool cmp1(node& a, node& b){
    return a.id<b.id;
}
int a[N],S[N][26];
bool st[26];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        
        int ans=0;
        
        string s;
        cin>>s;
        int n=s.size();
        
        for(int j=0;j<26;++j){
        	S[j][n]=0;
        	st[j]=0;
		} 
        
		int l=0,m=n-1,r=n-1;    
        for(int i=n-1;i>=0;--i){ 
			int t=s[i]-'a';
			if(!st[t]){
				st[t]=1;
				r=m,m=i;
			}
//            for(int j=0;j<26;++j){
//            	S[j][i]=S[j][i+1]+bool(j==t);
//            	cout<<S[j][i]<<" ";
//			}
//			puts("");
        }
        cout<<l<<" "<<m<<" "<<r<<endl;
        for(int )
        /*
        for(int j=0;j<26;++j){
        	cout<<S[j][i];
		}
        */
        printf("%d\n",ans);
    }
    return 0;
}
