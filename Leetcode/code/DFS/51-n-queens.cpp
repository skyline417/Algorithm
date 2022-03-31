/*
题意：N皇后
思路：dfs
*/
class Solution {
public:
    int a[10]; //第i行的皇后放在第a[i]列
    bool st[20],d[20],dv[20];
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        dfs(0,n);
        return res;
    }
    void dfs(int h, int n){
        if(h==n){
            
            vector<string>v;
            for(int i=0;i<n;++i){
                string s;
                for(int j=0;j<n;++j){
                    if(a[i]==j) s+='Q';
                    else s+='.';
                }
                v.push_back(s);
            }
            res.push_back(v);
            return;
        }

        //放在哪一列
        for(int i=0;i<n;++i){
            if(!st[i] && !d[h+i] && !dv[i+n-h]){//列、反对角线、对角线
                
                a[h]=i;
                st[i]=1;
                d[h+i]=1;
                dv[i+n-h]=1;

                dfs(h+1,n);
                

                a[h]=0;
                st[i]=0;
                d[h+i]=0;
                dv[i+n-h]=0;
            }
        }

    }
};