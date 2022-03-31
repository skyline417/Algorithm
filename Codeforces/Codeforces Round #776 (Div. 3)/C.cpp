#include<bits/stdc++.h>
using namespace std;
const int N=100005*2;
typedef long long ll;

struct node{
    int w,p,id,s;
}a[N],b[N];

bool cmp1(node& x, node& y){
    return x.w<y.w;
}
bool cmp2(node& x, node& y){
    return x.p<y.p;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);

        for(int i=1;i<=m;++i){
            a[i].id=i;
            cin>>a[i].p>>a[i].w;
            a[i].s=0;
        }

        sort(a+1,a+1+m,cmp1);
        ll ans=0;
        for(int i=1;i<=2*n;++i){
            b[i]=a[i];
            ans+=a[i].w;
        }

        sort(b+1,b+2*n+1,cmp2);
        printf("%lld\n",ans);
        for(int i=1;i<=n;++i){
            cout<<b[i].id<<" "<<b[2*n+1-i].id<<"\n";
        }
        puts("");

        
    }
    return 0;
}

