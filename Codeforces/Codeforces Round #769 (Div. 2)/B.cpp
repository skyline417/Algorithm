#include<bits/stdc++.h>
using namespace std;
const int N=100005;
typedef long long ll;
int a[]={1,2,4,8,16,32,
64,128,256,512,1024,2048,
4096,8192,16384,32768,65536,131072};
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,p;
        scanf("%d",&n);

        for(int i=0;i<18;++i){
            if(a[i]<=n){
                p=i;
            }else break;
        }

        for(int i=1;i<a[p];++i){
            cout<<i<<" ";
        }
        cout<<"0 ";
        for(int i=a[p];i<n;++i){
            cout<<i<<" ";
        }
        puts("");
    }
    return 0;
}