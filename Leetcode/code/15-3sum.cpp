/*
题意：找出数组中所有和为0的三元组。
思路：双指针 一定得是在有序数组上操作 先排序
    当i固定后 nums[j]+nums[k]+nums[i]>=0
    暴力枚举j,k o(n^2)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i){
            if(i&&nums[i]==nums[i-1]) continue;
            for(int j=i+1, k=nums.size()-1; j<k; ++j){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                while(j<k-1&&nums[i]+nums[j]+nums[k-1]>=0)--k; //为何是k-1呢？因为和>=0配合。退出循环时，是<0，那么和k必然是>=0;
                if(nums[i]+nums[j]+nums[k]==0) res.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return res;
    }
};