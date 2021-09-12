#include<bits/stdc++.h>
using namespace std;

const int N=5005;

char a[N],s[N];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        
        scanf("%d%s",&n,a+1);
        
        for(int i=1;i<=n;++i){
            if(a[i]=='U') s[i]='D';
            else if(a[i]=='D') s[i]='U';
            else s[i]=a[i];
        }
        printf("%s\n",s+1);
    }
    return 0;
}

