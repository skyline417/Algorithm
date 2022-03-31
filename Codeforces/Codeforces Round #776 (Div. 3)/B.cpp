#include<bits/stdc++.h>
using namespace std;
const int N=100005;
typedef long long ll;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        ll l,r,a;
        cin>>l>>r>>a;

        ll r1=l%a, r2=r%a, b=a-1;
        if(r-l+1<a){ //不足一个循环
            //找最大的余数
            if(r2>=r1){
                b=r2%a;
            }
        }
        //3456
        //0120
        
        ll f=(r-b)/a*a;
        ll ans=f/a + b;

        
        printf("%lld\n",ans);
    }
    return 0;
}