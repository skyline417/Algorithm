#include<bits/stdc++.h>
using namespace std;
const int N=100005;
typedef long long ll;
int a[N];
int main(){
    // //1 2 3 0 4
    int n,ans=0,res=0x3f3f3f3f;
    cin>>n;

    for(int i=0;i<n;++i){
        a[i]=i;
    }
    do{
        
        for(int i=0;i<n-1;++i){
            ans=max(a[i]^a[i+1],ans);
        }
        cout<<ans<<":  ";
        for(int i=0;i<n;++i){
            cout<<a[i]<<" ";
        }
        puts("");
        res=min(res,ans);
        ans=0;
    }while(next_permutation(a,a+n));

    //cout<<ans<<endl;
    // for(int i=0;;++i){

    
    //     int m=pow(2,i);
    //     cout<<m<<",";
    //     if(m>2e5) break;
    // }
    return 0;
}