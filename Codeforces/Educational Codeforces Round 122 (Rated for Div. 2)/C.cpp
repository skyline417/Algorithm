#include<bits/stdc++.h>
using namespace std;
const int N=100005;
typedef long long ll;


int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        bool flag=0;
        int hc,dc,hm,dm,k,w,a;
        scanf("%d%d%d%d%d%d%d",&hc,&dc,&hm,&dm,&k,&w,&a);
        //对方多少次把我打死
        int c1=hc/dm+bool(hc%dm);
        //我多少次把对方打死
        int c2=hm/dc+bool(hm%dc);
        //花钱 使c2<=c1即可（我先出手 所以可以取等号）
        //增强我的武力值 可以减小c2
        //增强我的健康值 可以增加c1
        /*
        设x coin 花在武力 (k-x) coin 花在健康
        判断是否
        hc
        */
        int a=-a*w, b=hc*w-a*dc+k*a*w, c=hc*dc+k*a*dc-hm*dm;
        int x[10];
        if(a==0){ //一次方程
            x[0]=-c/b;
        }else{
            x[1] = (-b+sqrt(b*b-4*a*c))/(2*a), x[2] = (-b-sqrt(b*b-4*a*c))/(2*a);

        }
        
        
        
        for(int i=0;i<n;++i){
            int c1=hc+x[i]/dm+bool(hc%dm);
            int c2=hm/(dc+x[i])+bool(hm%dc);
        }
        printf("%d\n",ans);
    }
    return 0;
}