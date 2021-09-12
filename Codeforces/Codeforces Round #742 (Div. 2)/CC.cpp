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
ll sub(ll a, ll b){ //a-b
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
	ll C[20]={0},carry[20]={0},t;
	for(int i=0;i<la;++i){
		t=A[i];
		if(i<lb) t-=B[i];
		
		
		t=t-carry[i];
		
		
		C[lc++]=(t+10)%10;
		if(t<0) carry[i+2]=1;
		//cout<<t<<" "<<carry[i+]<<endl;
	}
	if(t<0||carry[la]||carry[la+1]) return -1;
	//cout<<t<<" "<<carry[la]<<" "<<carry[la+1]<<endl;
	
	
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
//	while(1){
//		ll a,b;
//		cin>>a>>b;
//		cout<<sub(a,b)<<endl; 
//	}
    //cout<<add(2039,2976)<<endl;
    
    
    
    int T;
    scanf("%d",&T);
    while(T--){
        ll n;
		ll ans=0;
        scanf("%lld",&n);
        for(ll i=1;i<n;++i){
        	ll t=sub(n,i);
        	if(sub(n,i)!=-1) ++ans;
		}
        
        printf("%lld\n",ans);
    }
    return 0;
}
//12 2+10 1+11 11+1 10+2
//
//2021


