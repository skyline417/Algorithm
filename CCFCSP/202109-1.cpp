/*
题意：给定前缀最大值数组B，求原数组A的总和的最小值和最大值
思路：水题
*/
#include<bits/stdc++.h>
using namespace std;
const int N=105;
int b[N];
int main(){
    int n;
    cin>>n;
    int maxn=0,s1=0,s0=0;
    for(int i=0;i<n;++i){
        cin>>b[i];
        if(b[i]>maxn){
            maxn=b[i];
            s0+=b[i];
        } 
        s1+=maxn;
    }
    cout<<s1<<"\n"<<s0<<"\n";
    return 0;
}