#include<bits/stdc++.h>
using namespace std;

const int N=1005;
int a[N],cnt;

int main(){
    for(int i=1;cnt<=1000;++i){
        if(i%3!=0&&i%10!=3) a[++cnt]=i;
    }
    int T;
    scanf("%d",&T);
    while(T--){
        int k;
        scanf("%d",&k);
        //cout<<"ans: ";
        printf("%d\n",a[k]);
    }
    return 0;
}


