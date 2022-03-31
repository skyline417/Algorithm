#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,ans=0;
        scanf("%d",&n);
        string s;
        cin>>s;
        bool flag=0;
        for(int i=0;i<n;++i){
            if(i+1<n && s[i]==s[i+1]){
                flag=1;
            }else if(i+2<n && s[i]==s[i+2]){
                flag=1;
            }
        }
        if(!flag) puts("YES"); else puts("NO");
    }
    return 0;
}