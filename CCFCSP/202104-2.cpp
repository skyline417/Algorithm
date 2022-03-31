/*
题意：计算图中的“较暗像素”的个数
思路：二维前缀和
*/
#include<bits/stdc++.h>
using namespace std;
const int N=600+5;
int a[N][N],h[N][N];
int main(){
    int n,L,r,t;
    cin>>n>>L>>r>>t;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>h[i][j];
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+h[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            int x1=max(0,i-r-1), x2=min(n,i+r), y1=max(0,j-r-1), y2=min(n,j+r);
            int tmp=(a[x2][y2]-a[x1][y2]-a[x2][y1]+a[x1][y1]);
            if(tmp<=t*(y2-y1)*(x2-x1)) ++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}
