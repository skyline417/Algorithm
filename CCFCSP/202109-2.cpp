/*
题意：找到数p，将小于p的值都变为0，使数组中非0段个数最大
思路：a[i]凸 ans+1, a[i]凹 ans-1
*/
#include<bits/stdc++.h>
using namespace std;
const int N=5e5,M=1e4+5;
vector<int>pos[M];
bool vis[N];
int main(){
    int n,x;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x;
        pos[x].push_back(i);
    }
    int p=0,ans=0;
    for(int i=10000;i>=1;--i){ //从大到小访问
        for(auto e:pos[i]){
            p+=1-vis[e-1]-vis[e+1]; //如果两边都未访问 凸 +1 ; 如果两边都访问过 凹 -1
            vis[e]=1;
        }
        ans=max(ans,p);
    }
    cout<<ans<<endl;
    return 0;
}