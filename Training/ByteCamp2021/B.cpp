#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c[N];
int main(){
    int t,n,a,b;
    cin>>t;
    while(t--){
        cin>>n>>a>>b;
        if(abs(a-b)>1 || a+b+2>n){
            puts("-1");
        }else{
            
            if(a==b){
                for(int i=1;i<=n;++i){
                    c[i]=i;
                }
                for(int i=2;i<=a+b+1;i+=2){
                    swap(c[i],c[i+1]);
                }
            }else if(a-b==1){
                for(int i=1;i<=a+b+1;++i){
                    c[i]=n-(a+b+1)+i;
                }
                for(int i=2;i<a+b+1;i+=2){
                    swap(c[i],c[i+1]);
                }
                for(int i=a+b+2;i<=n;++i){
                    c[i]=n-i+1;
                }
                
            }else{ //b-a==1
                for(int i=1;i<=a+b+1;++i){
                    c[i]=a+b+1-i+1;
                }
                for(int i=a+b+2;i<=n;++i){
                    c[i]=i;
                }
                for(int i=2;i<a+b+1;i+=2){
                    swap(c[i],c[i+1]);
                }
            }
            for(int i=1;i<=n;++i){
                cout<<c[i]<<" ";
            }
            puts("");
        }
    }
}