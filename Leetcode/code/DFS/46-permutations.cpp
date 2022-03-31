/*
题意：全排列
思路：注意 每个数都不同 所以对下标i进行标记即可
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<int> t;
    bool st[10];
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
    void dfs(vector<int>& nums, int id){
        if(id==nums.size()){
            res.push_back(t);
        }
        for(int i=0;i<nums.size();++i){ //这边有循环 是因为 要在n个数里找哪个数安排在该位置（id）对比39题
            if(!st[i]){
                t.push_back(nums[i]);
                st[i]=1;
                dfs(nums,id+1);
                st[i]=0;
                t.pop_back();
            }
        }
    }
};