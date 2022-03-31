/*
题意：求距某点最近的三个点
思路：水题
*/
#include<bits/stdc++.h>
using namespace std;
const int N=200+5;
pair<double,int>d[N];
int main(){
    int n,x,y,a,b;
    cin>>n>>x>>y;
    for(int i=0;i<n;++i){
        cin>>a>>b;
        d[i].first=sqrt((x-a)*(x-a)+(y-b)*(y-b));
        d[i].second=i+1;
    }
    sort(d,d+n);
    cout<<d[0].second<<"\n"<<d[1].second<<"\n"<<d[2].second<<"\n";
    return 0;
}