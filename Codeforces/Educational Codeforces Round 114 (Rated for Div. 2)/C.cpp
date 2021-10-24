#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a[N],x,y,b[N];
int main(){
//    int T;
//    scanf("%d",&T);
//    while(T--){
        int n,m;
        
        scanf("%d",&n);
        ll s=0;
        for(int i=0;i<n;++i){
            scanf("%lld",&a[i]);
            s+=a[i];
        }
        
        

        sort(a,a+n);
        
        for(int i=0;i<n;++i){
            b[i]=s-a[i];
        }
        
		scanf("%d",&m);
		while(m--){
			
            scanf("%lld%lld",&x,&y);
            
			ll ans=1e18;
            
            int c=lower_bound(a,a+n,x)-a;
            if(c==n) c=n-1;
            ll t1,t2;
            t1=max(x-a[c],0ll)+max(y-b[c],0ll);
            
            //cout<<abs(a[c]-x)<<" "<<abs(b[c]-y)<<endl;
            
            if(c){
            	t2=max(x-a[c-1],0ll)+max(y-b[c-1],0ll);
			}
            ans=min(t1,t2);
//            cout<<"c="<<c<<endl;
//            cout<<"t1="<<t1<<endl;
//            cout<<"t2="<<t2<<endl;
            
            c=lower_bound(b,b+n,y)-b;
            if(c==n) c=n-1;
            t1=max(y-b[c],0ll)+max(x-a[c],0ll);
            if(c){
            	t2=max(y-b[c-1],0ll)+max(x-a[c-1],0ll);
			}
            ans=min(ans,min(t1,t2));
//            cout<<"c="<<c<<endl;
//            cout<<"t1="<<t1<<endl;
//            cout<<"t2="<<t2<<endl;
//            cout<<"ans-------------";
            printf("%lld\n",ans);
        }
        
//    }
    return 0;
}

