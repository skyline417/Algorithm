#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],m[N];
bool vis[N];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        m[a[i]]=i;
    }
    sort(a+1,a+1+n);
    int ans=0,ans0=0,ans1;
    for(int i=1;i<=n;i++){
        if(!vis[i])ans++;;
        int j=i;
        while(!vis[j]){
            vis[j]=1;
            j=m[a[j]];
        }
    }
    ans=n-ans;
    //cout<<"ans="<<ans<<endl;
    ans0=max(0,ans-k);
    if(!ans0 && ((k+(ans-ans0))&1)){
        ans0+=1;
    }
    ans1=min(n-1,ans+k);
    if(ans1==n-1 && ((k+(ans1-ans))&1)){
        ans1-=1;
    }
    if(ans0>ans1) swap(ans0,ans1);
    printf("%d %d\n",ans0,ans1);
    return 0;
}