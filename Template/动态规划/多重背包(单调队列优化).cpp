//多重背包 单调队列优化
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=20010;
int n,m;
int f[N],g[N],q[N];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int v,w,s; //体积、价值、数量
        cin>>v>>w>>s;
        memcpy(g,f,sizeof f); //f备份到g (注意f[k]是通过前面的旧值g[q[hh]]来更新，所以窗口在g数组上滑动)
        for(int j=0;j<v;j++){//分成[0,v) v个类 对每个类做滑动窗口
            int hh=0,tt=-1;
            for(int k=j;k<=m;k+=v){ //窗口: [j, j+v, j+2v...] j=m%v
                if (hh<=tt && q[hh]<k-s*v) hh++ ; //q[hh]不在窗口[k-sv,k-v]内，队头出队
                //注意 这里滑动窗口求的"最大值"，指的是 窗口中物品价值+还能放入的物品价值 的最大值
                //设f[x], 如果用g[k]比用g[q[tt]]更新f[x]获得更大价值, 则有g[q[tt]]-(q[tt]-x)/v*w<=g[k]-(k-x)/v*w，移项化简得下式
                while(hh<=tt && g[q[tt]]+(k-q[tt])/v*w<=g[k]) tt--;
                q[++tt]=k; //下标入队
                f[k]=g[q[hh]]+(k-q[hh])/v*w; //f[k]=窗口中的最大值+还能放入物品的价值 (k-q[hh])/v还能放入的物品个数
            }
        }
    }
    //两层内循环控制f[0..m]进出队各一次O(m)，最外层循环O(n)，时间复杂度O(nm)
    cout<<f[m]<<endl;
    return 0;
}
