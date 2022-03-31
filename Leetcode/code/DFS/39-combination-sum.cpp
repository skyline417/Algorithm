/*
题意：找出数字组合 总和为target 注意 每个数可以重复选择
思路：常规DFS 但我却写了很久... 有个小想法：
    就是 递归的参数带了id，那递归函数里就不用再循环 从id到n，因为递归的过程就是在执行这个循环啊
    第一次就是写了二重循环
    这题只要一重循环（枚举每个数选择的个数）
*/
class Solution {
public:
    int st[35];
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, 0, target);
        return res;
    }
    void dfs(vector<int>& candidates, int cur, int id, int target){
        if(cur==target){
            vector<int>tmp;
            for(int i=0;i<candidates.size();++i){
                for(int j=0;j<st[i];++j){
                    tmp.push_back(candidates[i]);
                }
            }
            res.push_back(tmp);
            return;
        }

        if(id==candidates.size()) return;
        
        for(int j=0;j*candidates[id]+cur<=target;++j){
            st[id]=j;
            dfs(candidates, cur+st[id]*candidates[id], id+1, target);
        }
        st[id]=0;
        
    }
};