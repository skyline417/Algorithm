/*
题意：统计每个灰度值的出现次数
思路：水题
*/
#include<bits/stdc++.h>
using namespace std;
const int N=256+5;
int h[N];
int main(){
    int n,m,L,x;
    cin>>n>>m>>L;
    for(int i=0;i<n*m;++i){
        cin>>x;
        ++h[x];
    }

// h 0 1 2 ... 15
//   1 1 1      1
// h 0 1 2 ... 8
//   2      1
    for(int i=0;i<L;++i){
        cout<<h[i]<<" ";
    }
    return 0;
}