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
int a[N],n;
int main(){
    
    for(n=1;n<=100000;++n) {
    	a[n]=n*n;
    	if(n>=1000000000/n) break;
	}
	
	int T;
    scanf("%d",&T);	
    while(T--){
        int k;
        scanf("%d",&k);
        int pos=lower_bound(a+1,a+1+n,k)-a;
        //cout<<"squar: "<<a[pos]<<endl;
//        1+3+5+7+...+2n-1
//        n^2
		int r, c;
		int d = a[pos]-k;
		if(d>=pos){
			c=pos;
			r=2*pos-d-1;
		}else{
			r=pos;
			c=1+d;
		}
		
    	cout<<r<<" "<<c<<endl;
    }
    return 0;
}
