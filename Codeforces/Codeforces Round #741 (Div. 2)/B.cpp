#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
struct node{
    int x,y,id;
    bool operator < (const node& t) const {
        return x<t.x;
    }
}c[N];
bool cmp1(node& a, node& b){
    return a.id<b.id;
}
int p[30]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
bool st[100];
int main(){
	for(int i=1;i<=25;++i) st[p[i]]=1;
    int T;
    scanf("%d",&T);
    
    while(T--){
        int k;
        scanf("%d",&k);
        string s;
        cin>>s;
        int ans=0,t=0;
        for(int i=0;s[i];++i){
        	int a=s[i]-'0';
        	if(!st[a]){
        		ans=a;
        		t=1;
        		break;
			}
		}
        if(!ans){
        	for(int i=0;s[i];++i){
        		for(int j=i+1;s[j];++j){
        			int a=(s[i]-'0')*10+s[j]-'0';
		        	if(!st[a]){
		        		t=2;
		        		ans=a;
		        		break;
					}
				}
				if(ans) break;
			}
		}
        //cout<<"----:\n";
        printf("%d\n%d\n",t,ans);
        //cout<<"----:\n";
    }
    return 0;
}
