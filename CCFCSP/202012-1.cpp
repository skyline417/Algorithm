/*
题意：代入公式求值
思路：水题
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,w,s,sum=0;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>w>>s;
        sum+=w*s;
    }
    cout<<max(0,sum)<<endl;
    return 0;
}