#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+5;
struct node{
    int x,y,id;
    bool operator < (const node& t) const {
        return x<t.x;
    }
}c[N];
bool cmp1(node& a, node& b){
    return a.id<b.id;
}
ll add(ll a, ll b){
	ll aa=a,bb=b;
	ll A[20]={0}, B[20]={0};
	int la=0,lb=0,lc=0;
	while(a){
		A[la++]=a%10;
		a/=10;
	}
	while(b){
		B[lb++]=b%10;
		b/=10;
	}
	ll C[20]={0},carry[20]={0};

	for(int i=0;i<la;++i){
		int t=0;
		t+=A[i];
		if(i>=2) t+=carry[i-2];
		if(i<lb) t+=B[i];
		C[lc++]=t%10;
		carry[i]=t/10;
	}
	if(carry[la-2]) C[lc++]=carry[la-2];
	if(carry[la-1]) {
		if(!carry[la-2]) C[lc++]=0;
		C[lc++]=carry[la-1];
	}
	
	ll cc=0;
	for(int i=lc-1;i>=0;--i){
		cc=cc*10+C[i];
	}
	return cc;
}
map<int,ll>mp;
int main(){
	
//	for(ll i=1;i<=999;++i){
//    	for(int j=i;j<=999;++j){
//    		if(i==j) ++mp[add(j,i)]; //j>=i 
//    		else mp[add(j,i)]+=2;
//		}
//    }
//    for(auto e: mp){
//    	cout<<e.first<<" "<<e.second<<endl;
//	}
	while(1){
		ll a,b;
		cin>>a>>b;
		cout<<add(a,b)<<endl; 
	}
    //cout<<add(2039,2976)<<endl;
    
    
    
    int T;
    scanf("%d",&T);
    while(T--){
        int n;

        scanf("%d",&n);
        int nn=n;
        ll cnt=1;
        while(nn){
        	cnt*=10;
        	nn/=10;
		}
		cnt/=10,cnt/=10;
		nn=n;
		nn%=cnt;
		cout<<"nn="<<nn<<endl;
		ll ans=0;
        for(int i=1;i<=(nn+1)/2;++i){
        	int j=nn-j;
        	if(i<j) swap(i,j);
        	ll t=add(i,j);
        	if(t==n){
        		if(i==j) ++ans;
        		else ans+=2;
			}
		}
        printf("%lld\n",ans);
    }
    return 0;
}
//12 2+10 1+11 11+1 10+2
//
//2021


