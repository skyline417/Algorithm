#include<bits/stdc++.h>
using namespace std;
const int N=100005;
typedef long long ll;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        string a;
        char b;
        cin>>a>>b;
        int n=a.size();
        bool flag=0;
        for(int i=0;a[i];++i){
            if(a[i]==b){
                //01234 n=5
                if( (!(i&1)) && ((n-i)&1) ){
                    flag=1;
                    break;
                }
            }
        }
        if(flag) puts("YES"); else puts("NO");
    }
    return 0;
}