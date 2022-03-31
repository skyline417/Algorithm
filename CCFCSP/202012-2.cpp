/*
题意：求最佳阈值
思路：前缀和
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+5;

pair<int,int>p[N];
ll s[N];
int main(){
    int m,ans=0;
    cin>>m;
    for(int i=1;i<=m;++i){
        cin>>p[i].first>>p[i].second;
    }
    sort(p+1,p+m+1);
    for(int i=1;i<=m;++i){
        s[i]=s[i-1]+p[i].second;

    }
    int maxr=0;
    for(int i=1;i<=m;++i){
        if(p[i].first==p[i+1].first) continue;
        int rate=(s[m]-s[i])+(i-s[i]);
        if(rate>=maxr){
            maxr=rate;
            ans=p[i+1].first;
        }
    }
    cout<<ans<<"\n";

    return 0;
}