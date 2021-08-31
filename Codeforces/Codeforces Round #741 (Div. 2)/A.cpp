#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int l,r;
        int ans=0;
        scanf("%d%d",&l, &r);
        cout<< r % max(r/2+1, l) <<endl;
    }
    return 0;
}
