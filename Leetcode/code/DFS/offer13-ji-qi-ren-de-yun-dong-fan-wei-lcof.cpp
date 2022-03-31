/*
题意：机器人的运动范围 机器人从(0,0)开始走 他只能进入坐标数位和小于k的格子 问它能走到几个格子 
思路：dfs 注意细节 在代码中有写
*/
class Solution {
public:
    int dir[4][2]={
        0,1,
        0,-1,
        1,0,
        -1,0
    };
    int st[105][105];
    int ans[105][105];
    int res=0;
    int movingCount(int m, int n, int k) {
        st[0][0]=1; //注意（0,0）也要标记！
        dfs(0,0,m,n,k);
        return res;
    }
    bool check(int x,int y,int k){
        int sum=0;
        while(x){
            sum+=x%10;
            x/=10;
        }
        while(y){
            sum+=y%10;
            y/=10;
        }
        return sum<=k;
    }
    void dfs(int x,int y,int m,int n,int k){
        ++res;//每进来一次就计数 因为标记过的位置不会再进来 所以只会进来一次
        for(int i=0;i<4;++i){
            int nx=x+dir[i][0], ny=y+dir[i][1];
            if(nx>=0 && nx<m && ny>=0 && ny<n && !st[nx][ny] && check(nx,ny,k)){
                st[nx][ny]=1;
                dfs(nx,ny,m,n,k); 
                //不要清空标记 会超时 每个位置都会往4个方向走 所以不回溯不会漏掉
            }
        }
    }
};