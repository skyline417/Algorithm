#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        string s;
        cin>>s;
        int a=0,b=0;
        for(int i=0;s[i];++i){
            if(s[i]=='0') ++a;
            else ++b;
        }
        if(a!=b) cout<<min(a,b)<<endl;
        else cout<<a-1<<endl;
    }
    return 0;
}