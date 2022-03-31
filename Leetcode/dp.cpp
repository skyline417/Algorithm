/*
题意：若干堆金币 不能取相邻 最多能拿多少？
思路：DP
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n+1],dp[n+1]={0};//dp[i]表示1~i堆的最大值
    for(int i=1;i<=n;++i) cin>>a[i];
    dp[1]=a[1];//初始化
    for(int i=2;i<=n;++i){
        dp[i]+=max(dp[i-1],dp[i-2]+a[i]);//状态转移方程
    }
    cout<<dp[n]<<endl;
}