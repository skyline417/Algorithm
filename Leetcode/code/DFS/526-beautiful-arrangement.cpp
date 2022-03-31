/*
题意：给定n，找n的优美排列的个数。优美排列a[]：for each i, 满足 i能被a[i]整除 或 a[i]能被i整除
思路：爆搜(排列) 搜的过程中 满足条件的才继续递归下去 而不是到递归边界才判断 否则会超时
*/
class Solution {
public:
    bool st[20];
    int a[20];
    int ans=0;
    int countArrangement(int n) {
        dfs(a,1,n);
        return ans;
    }
    void dfs(int a[], int c,int n){
        if(c==n+1){ //递归边界是n+1
            ++ans;
            return;
        }
        //这边这个循环 每次递归看（递归其实是从第0位到第n位 递归这个id） 选哪个数放在当前位置
        for(int i=1;i<=n;++i){ //从1开始看每一个值 是否未被访问过
            if(!st[i]) {
                if(i%c==0 || c%i==0){ //满足条件才考虑 否则往后找下一个值（continue）
                    a[c]=i;
                    st[i]=1;
                    dfs(a,c+1,n);
                    st[i]=0;
                }
            }
        }
    }
};