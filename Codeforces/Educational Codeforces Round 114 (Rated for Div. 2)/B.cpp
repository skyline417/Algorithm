#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[3];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        ll m;
        scanf("%lld%lld%lld%lld",&a[0],&a[1],&a[2],&m);
        bool ans=1;
        //最多有多少对  
        if(m>a[0]+a[1]+a[2]-3) ans=0;
        //最少有多少对 
        sort(a,a+3);
        //m < abs((a[1]-a[0])-(a[2]-a[0]))-1 &&
        ll minn; 
        if(a[2]>a[0]+a[1]+1) minn=a[2]-(a[0]+a[1]+1);else minn=0;
        if(m<minn) ans=0;
        if(ans) puts("YES"); else puts("NO");
    }
    return 0;
}
