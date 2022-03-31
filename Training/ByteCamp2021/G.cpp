#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5, p1=39623, p2=39989;
int qmi(int a,int b,int p){
    int res=1%p;
    while(b){
        if(b&1) res=res*a%p;
        a=a*(ll)a%p;
        b>>=1;
    }
    return res;
}
pair<pair<int,int>,int>p[N+5],t;
int main(){
    for(int i=1;i<=N;++i){
        p[i].first.first=qmi(i,i,p1);
        p[i].first.second=qmi(i,i,p2);
        p[i].second=i;
    }
    sort(p+1,p+1+N);

    int T;
    cin>>T;
    while(T--){
        cout<<"? "<<p1<<endl;
        cin>>t.first.first;
        cout<<"? "<<p2<<endl;
        cin>>t.first.second;
        t.second=0;
        cout<<"! "<<(*lower_bound(p+1,p+1+N,t)).second<<endl;
    }
    return 0;
}
